#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define INF 1000000000
#define MAX_N 300000
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
vector<ll> G[MAX_N];
bool used[MAX_N];
ll n,max_l=0;
ll dfs(ll v){
  used[v]=true;
  ll fi=0,se=0,tmp;
  for(auto to:G[v]){
    if(!used[to]){
      tmp = dfs(to);
      if(tmp>=fi){
        se=fi;
        fi=tmp;
      }else if(tmp>=se){
        se = tmp;
      }
    }
  }
  max_l = max(max_l,fi+se);
  return fi+1;
}
signed main(){
  cin >> n;
  ll a[n],b[n];
  fill(used,used+MAX_N,false);
  queue<P> que;
  for(int i=0;i<n-1;i++){
    cin >> a[i]>>b[i];
    a[i]--;
    b[i]--;
    G[a[i]].push_back(b[i]);
    G[b[i]].push_back(a[i]);
  }
  dfs(0);
  if(max_l%3==1){
    cout <<"Second\n";
  }else{
    cout << "First\n";
  }
}
