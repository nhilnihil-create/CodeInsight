#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const ll MOD = 1000000007;

ll modPow(ll a, ll n) {
  if (n == 0) return 1; // 0乗にも対応する場合
  if (n == 1) return a % MOD;
  if (n % 2 == 1) return (a * modPow(a, n - 1)) % MOD;
  ll t = modPow(a, n / 2);
  return (t * t) % MOD;
}


int main(){
  ll N,ans=1;
  string S;
  cin >> N >> S;
  vector<ll> A(26,0);
  rep(i,N){
    A.at(S.at(i)-'a')++;
  }
  rep(i,26){
    ans*=A.at(i)+1;
    ans%=MOD;
  }
  ans+=MOD;
  ans--;
  ans%=MOD;
  cout << ans << endl;
    
 
      
}