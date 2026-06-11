#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define mat vector<vec>

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

vector<vector<ll>> bunkai(ll a){
  if(a<=0) return {};
  if(a==1) return {{1,1}};
  vector<ll> f;
  for(ll j=2;j<=a;j++){
    ll b=j;
    for(ll i=2;i*i<=a;i++){
      if(b%i==0){
        f.push_back(i);
        b=b/i;
        i--;
      }
    if(b==1)break;
    }
    if(b!=1)f.push_back(b);
  }

  sort(f.begin(),f.end());
  vector<vector<ll>> u;
  ll p=f[0];
  ll c=1;
  for(ll i=1;i<f.size();i++){
    if(f[i]==p)c++;
    else{
      u.push_back({p,c});
      p=f[i];
      c=1;
    }
  }
  u.push_back({p,c});

  return u;
}

int main(){

  ll n;
  cin >> n;
  mat G=bunkai(n);
  vec a(150);
  for(ll i=0;i<G.size();i++){
    if(G[i][0]!=1)a[G[i][1]]++;
  }

  for(ll i=148;i>=0;i--){
    a[i]+=a[i+1];
  }

  ll ans=0;
  ans+=a[74];//75=75
  ans+=a[24]*(a[2]-1);//75=(2+1)*(24+1)
  ans+=a[14]*(a[4]-1);//75=(4+1)*(14+1)
  ans+=(a[4])*(a[4]-1)/2*(a[2]-2); //75=(2+1)*(4+1)*(4+1)

  cout << ans << endl;




}