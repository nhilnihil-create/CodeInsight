#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
//const ll MOD = ;
ll mod(ll A, ll M) {return (A % M + M) % M;}
const ll INF = 1LL << 60;
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
ll divceil(ll A, ll B) {return (A + (B - 1)) / B;}
ll myctoi(char C) {return C - '0';}
char myitoc(ll N) {return '0' + N;}
#define FINALANS(A) {cout << (A) << '\n'; exit(0);}

ll modinv(ll a, ll m)
{
  ll b = m, x = 1, y = 0;
  while (b > 0)
  {
    ll q = a / b, r = a - q * b, s = x - q * y;
    a = b, b = r;
    x = y, y = s;
  }
  return mod(x, m);
}

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }

  vector<ll> S(N + 1);
  S.at(0) = 0, S.at(1) = 0;
  for (ll i = 2; i <= N; i++)
  {
    S.at(i) = (S.at(i - 1) + modinv(i, MOD)) % MOD;
  }

  ll ans = 0;
  for (ll i = 0; i < N; i++)
  {
    ll tmp = A.at(i) * (S.at(i + 1) + 1 + S.at(N - i));
    ans += tmp;
    ans %= MOD;
  }
  for (ll i = 1; i <= N; i++)
  {
    ans *= i;
    ans %= MOD;
  }
  cout << ans << endl;
}