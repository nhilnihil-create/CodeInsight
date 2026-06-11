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
#define mt make_tuple
#define pqueue priority_queue
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
  vector<int> C(N);
  for(int i=0;i<N;++i) cin>>C[i];
  sort(C.begin(), C.end(), greater<int>());
  queue<int> que;
  que.push(0);
  int ans[N];
  for(int i=0;i<N;++i) ans[i] = -1;
  int state;
  int index = 0;
  while(!que.empty()) {
    state = que.front();que.pop();
    if(ans[state]>-1) continue;
    ans[state] = index;
    index++;
    for(int i=0;i<edge[state].size();++i) {
      if(ans[edge[state][i]]>-1) continue;
      que.push(edge[state][i]);
    }
  }
  int ans1 = 0;
  for(int i=1;i<N;++i) {
    ans1 += C[i];
  }
  cout<<ans1<<endl;
  for(int i=0;i<N;++i) cout<<C[ans[i]]<<" ";
  cout<<endl;
}

