  #include <bits/stdc++.h>
  using namespace std;

  const int MOD = 1000000007;
  const double PI = acos(-1); 

  //long long
  using ll = long long;

  //出力系
  #define print(x) cout << x << endl
  #define yes cout << "Yes" << endl
  #define YES cout << "YES" << endl
  #define no cout << "No" << endl
  #define NO cout << "NO" << endl
  
  // begin() end()
  #define all(x) (x).begin(),(x).end()

  //for
  #define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

  //最大公約数（ll）
  ll gcd(ll x, ll y) { return y ? gcd(y,x%y) : x;}

  //素因数分解
  vector<pair<ll, int>>factorize(ll n){
    vector<pair<ll, int>> res;
    for(ll i = 2; i * i <= n; ++i){
      if(n % i) continue;
      res.emplace_back(i, 0);
      while(n % i == 0){
        n /= i;
        res.back().second++;
      }
    }
  if(n != 1) res.emplace_back(n, 1);
  return res;
  }



// // 二分探索(最小値を出す問題は疑う)
// bool C(ll x){
//     ll res = 0;
//     for(int i = 0; i < N; ++i){
// 		res += max(0ll, A[i]-x/F[i]);
//     }
//     return res <= K;
// }

//   ll binary_search(ll ok, ll ng){
//     while(abs(ok - ng) > 1){
//       ll mid = (ok + ng) / 2;
//       if(C(mid)) ok = mid;
//       else ng = mid;
//     }
//     return ok;
//   }



int main() {
string S;
cin >> S;
int w;
cin >> w;
string ans;
int i = 0;
while(i < S.size()){
  ans += S.at(i);
  i += w;
}
print(ans);
}