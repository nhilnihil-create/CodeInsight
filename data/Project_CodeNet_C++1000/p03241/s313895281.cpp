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

const ll MOD = 998244353;
const ll MAX = 2000001;

ll mod(ll a){
  if(a % MOD < 0) return MOD + (a % MOD);
  return a % MOD;
}

ll lcm(ll a,ll b){
  return (a*b)/gcd(a,b);
}


int main(){
  ll n,m; cin >> n >> m;
  
  ll ans = 0;
  
  for(ll i=1; i*i <= m; i++){
    if(m % i == 0){
      if(m/i >= n) ans = max(ans,i);
      if(i >= n) ans = max(ans,m/i);
    }
  }
  
  
  cout << ans << endl;
  
}