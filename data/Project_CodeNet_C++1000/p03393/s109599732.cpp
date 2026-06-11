#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define pa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
#define pb push_back

using ll = long long;
using namespace std;
using pint = pair<int,int>;
using pll = pair<ll,ll>;
const int INFint = 1e9;
const ll INFll = 1e18;
ll MOD=1e9+7;

ll gcd(ll a, ll b) { return __gcd(a,b); } //最大公約数
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; } //最大公倍数

// aのn乗をMODで割りながら計算する
ll modpow(ll a, ll n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % MOD;
    a = a * a % MOD;
    n >>= 1; // right shift
  }
  return res;
}

// MODを法としたaの逆元を計算する
ll modinv(ll a) {
  return modpow(a, MOD - 2);
}

int main(){
  string s; 
  cin>>s;
  int N = int(s.size());
  if (int(s.size()) == 26){
    if (s == "zyxwvutsrqponmlkjihgfedcba"){
      cout << -1 << endl;
    }else{
      string t = s;
      next_permutation(s.begin(), s.end());
      for (int i(0);i<26;i++){
        if (s[i] == t[i]){
          cout << s[i];
        }else{
          cout << s[i] << endl;
          return 0;
        }
      }
      cout << s << endl;
    }
  }else{
    int cnt[30] = {0};
    for (int i(0);i<N;i++){
      cnt[s[i]-'a']++;
    }
    for (int i(0);i<26;i++){
      if (cnt[i] == 0){
        cout << s + (char)('a' + i) << endl;
        return 0;
      }
    }
  }
  return 0;
}
