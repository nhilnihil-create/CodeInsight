#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#include<algorithm>//next_permutation
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
#define dec(n) cout << fixed << setprecision(n);
#define large "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define small "abcdefghijklmnopqrstuvwxyz"
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;

ll gcd(ll a,ll b){
  if(b == 0) return a;
  return gcd(b , a % b);
}

ll mod1e7(ll a){
  return (a % 1000000007);
}

ll mod1e9(ll a){
  return (a % 1000000009);
}

ll mod998(ll a){
  return (a % 998244353);
}

ll lcm(ll a,ll b){
  return (a*b)/gcd(a,b);
}

vector<ll> fac(200001);
void factorial(){
  fac[0] = 1; 
  for(ll i=1; i < 200001; i++){
    fac[i] = mod998(fac[i-1]*i);
  }
}
    
ll nCr(ll n,ll r){
  if(r == 1) return n;
  else if(r == 0) return 1;
  else return mod998(fac[n]/fac[r]/fac[n-r]);
}

int main(){
  string s; cin >> s; ll cnt1 = 0; 
  
  rep(i,(long long)(s.size())){
    if(s[i] == '1') cnt1++;
  }
  
  cout << min(cnt1,(long long)(s.size()) - cnt1)*2 << endl;
  
  
}