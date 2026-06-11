#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> t(N), v(N);
  for(int i = 0; i < N; i++) cin >> t[i];
  for(int i = 0; i < N; i++) cin >> v[i];

  int T = 0;
  for(int i = 0; i < N; i++){
    T += t[i];
  }

  vector<double> maxV(2 * T + 1, (double)(1e9));

  int nowT = 0;
  for(int i = 0; i < N; i++){
    for(int ti=0; ti < t[i]; ti++){
      int t1 = nowT + ti * 2;
      int t2 = nowT + ti * 2 + 1;
      maxV[t1] = min(maxV[t1], double(v[i]));
      maxV[t2] = min(maxV[t2], double(v[i]));
    }
    nowT += t[i] * 2;
    maxV[nowT] = min(maxV[nowT], double(v[i]));
  }

  maxV[0] = maxV[T*2] = 0.0;
  for(int ti = 0; ti < 2*T+1; ti++){
    maxV[ti+1] = min(maxV[ti+1], maxV[ti]+0.5);
  }

  for(int ti = 2*T; ti >= 0; ti--){
    maxV[ti] = min(maxV[ti], maxV[ti+1] + 0.5);
  }

  double ans = 0.0;
  for(int i =0; i < 2 * T + 1; i++){
    ans += (maxV[i] + maxV[i+1]) * 0.5 / 2.0;
  }
  cout << setprecision(10) << ans << endl;

  return 0;
}
