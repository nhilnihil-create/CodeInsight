#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
const int inf=1<<30;

int n,m;
vector<vector<int> > to;
vector<int> deg;
int dp[100010];

int main(){
  cin >> n >> m;
  to.resize(n);
  deg.resize(n);
  rep(i,n-1+m){
    int a,b;
    cin >> a >> b;
    a--; b--;
    to[a].push_back(b);
    deg[b]++;
  }
  queue<int> q;
  map<int,int> mp;
  rep(i,n)if(deg[i]==0) {q.push(i); mp[i]=0;}
  while(q.size()){
    int v=q.front(); q.pop();
    for(auto nv:to[v]){
      deg[nv]--;
      if(deg[nv]==0){
        q.push(nv);
        mp[nv]=v+1;
      }
    }
  }
  for(auto c:mp){
    cout << c.second << endl;
  }
}
