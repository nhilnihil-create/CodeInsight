#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

ll mazic(vector<ll> v,ll a){
  if(v.size()==1){
    return abs(a-v[0]);
  }
  ll m=inf;
  for(ll i=0;i<v.size();i++){
    m=min(m,abs(a-v[i]));
  }

  if(m==0)return 0;

  for(ll i=0;i<v.size()-1;i++){
    for(ll j=i+1;j<v.size();j++){
      vector<ll> u=v;
      u[i]+=u[j];
      swap(u[j],u[u.size()-1]);
      u.pop_back();
      m=min(m,mazic(u,a)+10);
    }
  }
  return m;

}

int main(){

  ll n,a,b,c;
  cin >> n >> a >> b >> c;

  ll l[n];
  for(ll i=0;i<n;i++)cin >> l[i];

  ll m=inf;
  for(ll i=1;i<(1<<n);i++){
    if(n-__builtin_popcountll(i)<=1)continue;
    vector<ll> v1;
    vector<ll> q;
    for(ll j=0;j<n;j++){
      if(i & (1<<j))v1.push_back(l[j]);
      else q.push_back(l[j]);
    }
    for(ll k=1;k<(1<<q.size());k++){
      if(__builtin_popcountll(k)==q.size())continue;
      vector<ll> v2,v3;
      for(ll t=0;t<q.size();t++){
        if(k & (1<<t))v2.push_back(q[t]);
        else v3.push_back(q[t]);
      }
      m=min(m,mazic(v1,a)+mazic(v2,b)+mazic(v3,c));
      //if(mazic(v1,a)+mazic(v2,b)+mazic(v3,c)==165)cout << i << " " << k << endl;
    }
  }

  // vector<ll> u;
  // u.push_back(100);
  // u.push_back(90);
  // u.push_back(80);
  // cout << mazic(u,253) << endl;

  cout << m << endl;


}