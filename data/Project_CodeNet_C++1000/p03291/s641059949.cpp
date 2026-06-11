#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int INT_INF = 1 << 30;
#define MOD 1000000007LL

ll beki(ll x, ll n){
  ll res = 1LL;
  while(n > 0){
    if(n & 1){
      res *= x % MOD;
      res %= MOD;
    }
    x = x * x % MOD;
    n >>= 1;
  }
  return res % MOD;
}

int main(){
  string S;
  cin >> S;
  ll N = S.size();
  vll dp1(N+1, 0LL), dp2(N+1, 0LL), dp3(N+1, 0LL);
  ll counter = 0LL;
  for(int i = 1; i <= N; i++){
    char c = S.at(i-1);
    if(c == '?') counter++;

    if(c == '?') dp1.at(i) = dp1.at(i-1) * 3LL % MOD + 1LL * beki(3LL, counter-1LL) % MOD;
    else if(c == 'A') dp1.at(i) = (dp1.at(i-1) + 1LL * beki(3LL, counter) % MOD) % MOD;
    else dp1.at(i) = dp1.at(i-1);
    dp1.at(i) %= MOD;

    if(c == '?') dp2.at(i) = (dp2.at(i-1) * 3LL % MOD + dp1.at(i-1)) % MOD;
    else if(c == 'B') dp2.at(i) = dp2.at(i-1) + dp1.at(i-1);
    else dp2.at(i) = dp2.at(i-1);
    dp2.at(i) %= MOD;

    if(c == '?') dp3.at(i) = (dp3.at(i-1) * 3LL % MOD + dp2.at(i-1)) % MOD;
    else if(c == 'C') dp3.at(i) = dp3.at(i-1) + dp2.at(i-1);
    else dp3.at(i) = dp3.at(i-1);
    dp3.at(i) %= MOD;
  }
  cout << dp3.at(N) << endl;
}
