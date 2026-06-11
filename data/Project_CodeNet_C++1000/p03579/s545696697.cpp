#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define dbg(x) cout<<#x<<":"<<x<<endl
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;

vector<ll> g[111111];

int used[111111];
int f;

void dfs(int n=0,int pr=0){
  if(used[n]!=-1){
    if(pr!=used[n])f=1;
    return;
  }
  used[n]=pr;
  for(int i=0;i<g[n].size();i++){
    dfs(g[n][i],(pr+1)%2);
  }
}

int main(){
  ll n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++){
    ll a,b;
    cin>>a>>b;
    a--,b--;
    g[a].pb(b);
    g[b].pb(a);
  }

  fill_n(used,111111,-1);
  dfs();
  if(f){
    cout<<(n-1)*n/2-m<<endl;
    return 0;
  }

  ll cnt[2]={};
  for(int i=0;i<n;i++){
    cnt[used[i]]++;
  }
  //  dbg(cnt[0]);  dbg(cnt[1]);
  cout<<cnt[0]*cnt[1]-m<<endl;
  
  return 0;
}
