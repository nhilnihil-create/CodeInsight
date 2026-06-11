#include <bits/stdc++.h>
#define int long long
using namespace std;
//const int MOD = pow(10, 9) + 7;
const int MOD = 998244353;
//const int MOD = ;
int mod(int A, int M) {return (A % M + M) % M;}
const int INF = 1LL << 60;
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc = "abcdefghijklmnopqrstuvwxyz";
template <class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template <class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
int divCeil(int A, int B) {return (A + (B - 1)) / B;}

int modinv(int a, int m)
{
  int b = m, x = 1, y = 0;
  while (b > 0)
  {
    int q = a / b, r = a - q * b, s = x - q * y;
    a = b; b = r;
    x = y; y = s;
  }
  return mod(x, m);
}

class combination
{
public:
  vector<int> fac, finv, inv;

  combination(int M)
  {
    fac = vector<int>(M, 1);
    finv = vector<int>(M, 1);
    inv = vector<int>(M, 1);

    for (int i = 2; i < M; i++)
    {
      fac.at(i) = fac.at(i - 1) * i % MOD;
      inv.at(i) = MOD - inv.at(MOD % i) * (MOD / i) % MOD;
      finv.at(i) = finv.at(i - 1) * inv.at(i) % MOD;
    }
  }

  int COM(int N, int K)
  {
    if (N < K) return 0;
    if (N < 0 || K < 0) return 0;
    return fac.at(N) * (finv.at(K) * finv.at(N - K) % MOD) % MOD;
  }
};

signed main()
{
  int N, A, B, K;
  cin >> N >> A >> B >> K;
  
  combination cmb(300100);

  int ans = 0;
  for (int i = 0; i <= N; i++)
  {
    int j = (K - A * i) / B;
    if (j < 0 || N < j || A * i + B * j != K) continue;

    ans += cmb.COM(N, i) * cmb.COM(N, j) % MOD;
    ans %= MOD;
  }
  
  cout << ans << endl;
}