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

int main()
{
  using ld = long double;
  cout << fixed << setprecision(15);

  ll N;
  cin >> N;
  vector<ll> t(N), v(N);
  for (ll i = 0; i < N; i++)
  {
    cin >> t.at(i);
  }
  for (ll i = 0; i < N; i++)
  {
    cin >> v.at(i);
  }
  ll T = accumulate(t.begin(), t.end(), 0LL);

  vector<ld> V(2 * T + 1, INF);
  V.at(0) = 0, V.at(2 * T) = 0;

  {
    ll tt = 0;
    for (ll i = 0; i < N; i++)
    {
      for (ll j = 0; j <= 2 * t.at(i); j++)
      {
        chmin(V.at(tt), (ld)v.at(i));
        tt++;
      }
      tt--;
    }
  }

  /*
  for (ll tt = 0; tt <= 2 * T; tt++)
  {
    cerr << (ld)tt / 2 << " " << V.at(tt) << endl;
  }
  */

  for (ll tt = 0; tt <= 2 * T - 1; tt++)
  {
    chmin(V.at(tt + 1), V.at(tt) + 0.5);
  }
  for (ll tt = 2 * T; tt >= 1; tt--)
  {
    chmin(V.at(tt - 1), V.at(tt) + 0.5);
  }

  /*
  for (ll tt = 0; tt <= 2 * T; tt++)
  {
    cerr << (ld)tt / 2 << " " << V.at(tt) << endl;
  }
  */

  ld ans = 0;
  for (ll tt = 0; tt <= 2 * T - 1; tt++)
  {
    ans += (V.at(tt) + V.at(tt + 1)) * 0.25;
  }
  cout << ans << endl;
}