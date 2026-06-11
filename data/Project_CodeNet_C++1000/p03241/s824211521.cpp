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
  ll b=a;
  for(ll i=2;i*i<=a;i++){
    if(b%i==0){
      f.push_back(i);
      b=b/i;
      i--;
    }
  if(b==1)break;
  }
  if(b!=1)f.push_back(b);

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

vector<ll> yakusu(ll a){
  if(a==1)return {1};
  vec v;
  for(ll i=1;i*i<=a;i++){
    if(a%i==0){
      v.push_back(i);
      v.push_back(a/i);
    }
  }
  sort(v.begin(),v.end());
  return v;
}

int main(){

  ll n,m;
  cin >> n>>m;

  vec v=yakusu(m);
  ll ans=1;
  for(ll i=0;i<v.size();i++){
    if(v[i]<=m/n)ans=max(ans,v[i]);
  }
  cout << ans << endl;




}