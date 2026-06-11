#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

vector<vector<ll>> soinsu(ll a){
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

int main(){

  ll n;
  cin >> n;
  ll c=0;
  for(ll i=1;i<=n;i++){
    if(i%2==0)continue;
    vector<vector<ll>> v=soinsu(i);
    if(v.size()==3){
      if(v[0][1]==1 && v[1][1]==1 && v[2][1]==1)c++;
    }
    if(v.size()==2){
      if(v[0][1]==1 && v[1][1]==3)c++;
      else if(v[0][1]==3 && v[1][1]==1)c++;
    }
    if(v.size()==1){
      if(v[0][1]==7)c++;
    }
  }
  cout << c << endl;

}