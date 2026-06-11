#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define pb push_back
#define mp make_pair
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)

ll n,m,l,r,d,val[100010]={};
vector<P> v[100010];
bool vis[100010]={},ans=1;

void dfs(ll i,ll va,bool key=0){
  if(vis[i]){
    if(key&&val[i]!=va) ans=0;
    return;
  }
  vis[i]=1;val[i]=va;
  fr(j,v[i].size()) dfs(v[i][j].first,va+v[i][j].second,1);
}

int main(){
  cin>>n>>m;
  fr(i,m){
    cin>>l>>r>>d;
    v[l].pb(mp(r,d));
    v[r].pb(mp(l,-d));
  }
  Fr(i,n) dfs(i,0);
  cout<<(ans?"Yes":"No")<<endl;
}