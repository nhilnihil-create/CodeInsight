#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N;
  cin>>N;
  vector<vector<int> > edge(N);
  int a, b;
  for(int i=0;i<N-1;++i) {
    cin>>a>>b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  vector<int> c(N);
  for(int i=0;i<N;++i) cin>>c[i];
  sort(c.begin(), c.end(), greater<int>());
  int ans = 0;
  for(int i=0;i<N-1;++i) ans += c[N-1-i];
  queue<int> que;
  int state;
  int index = 0;
  que.push(0);
  map<int, int> amap;
  while(!que.empty()) {
    state = que.front();que.pop();
    amap[state] = c[index];
    index++;
    for(int i=0;i<edge[state].size();++i) {
      if(amap[edge[state][i]]>0) continue;
      que.push(edge[state][i]);
    }
  }
  cout<<ans<<endl;
  for(int i=0;i<N;++i) cout<<amap[i]<<" ";
  cout<<endl;
}

