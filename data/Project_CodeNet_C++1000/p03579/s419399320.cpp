#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define pb push_back
#define ft first
#define sd second
#define mp make_pair
#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,n) for(int i=0;i++<n;)
#define ifr(i,n) for(int i=n-1;i>=0;i--)
#define iFr(i,n) for(int i=n;i>0;i--)

vector<ll> c[100010];
ll cnt[2]={};
bool vis[100010]={},pnt[100010],master=0;

void rec(int i=1,bool f=0){
  if(master) return;
  if(vis[i]){
    if(pnt[i]^f) master=1;
    return;
  }
  vis[i]=1;pnt[i]=f;cnt[f]++;
  fr(j,c[i].size()) rec(c[i][j],1-f);
}

int main(){
  ll n,m,a,b;
  cin>>n>>m;
  fr(i,m){
    cin>>a>>b;
    c[a].pb(b);
    c[b].pb(a);
  }
  rec();
  if(master) cout<<(n*(n-1))/2-m<<endl;
  else cout<<cnt[0]*cnt[1]-m<<endl;
}