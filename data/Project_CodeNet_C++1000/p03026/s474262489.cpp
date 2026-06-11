#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef vector<pair<ll,ll> > vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
const int INF=1e9+7;

int main(){
  ll n,sum=0;cin>>n;
  vll ans(n,-1),d(n);vvb g(n,vb(n,false));
  priority_queue<ll> c;
  rep(i,0,n-1){
    ll a,b;
    cin>>a>>b;
    a--;b--;
    g[a][b]=true;g[b][a]=true;
  }
  rep(i,0,n){
    int C;cin>>C;
    c.push(C);
    d[i]=C;
  }
  queue<ll> q;
  q.push(0);
  ans[0]=c.top();c.pop();
  while(!q.empty()){
    ll now=q.front();q.pop();
    rep(i,0,n){
      if(g[now][i]&&ans[i]==-1){
        ans[i]=c.top();c.pop();
        q.push(i);

      }
    }
  }
  sort(d.begin(),d.end());
  rep(i,0,n-1){
    sum+=d[i];
  }
  cout<<sum<<endl;
  rep(i,0,n){
    cout<<ans[i]<<" ";
  }
  cout<<endl;
}
