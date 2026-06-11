#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//const ll MOD = 1e9 + 7;
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
  ll N, K;
  cin >> N >> K;
  vector<ll> X(N), Y(N), X0(N), Y0(N);
  for (ll i = 0; i < N; i++)
  {
    cin >> X.at(i) >> Y.at(i);
    X0.at(i) = X.at(i), Y0.at(i) = Y.at(i);
  }
  sort(X0.begin(), X0.end());
  sort(Y0.begin(), Y0.end());

  ll ans = 5 * 1e18;
  for (ll i0 = 0; i0 < N; i0++)
  {
    for (ll i1 = i0 + 1; i1 < N; i1++)
    {
      for (ll j0 = 0; j0 < N; j0++)
      {
        for (ll j1 = j0 + 1; j1 < N; j1++)
        {
          ll x0 = X0.at(i0), x1 = X0.at(i1);
          ll y0 = Y0.at(j0), y1 = Y0.at(j1);

          ll tmp = (x1 - x0) * (y1 - y0);

          ll cnt = 0;
          for (ll k = 0; k < N; k++)
          {
            ll x = X.at(k), y = Y.at(k);
            if (x0 <= x && x <= x1 && y0 <= y && y <= y1)
              cnt++;
          }
          if (cnt >= K)
            chmin(ans, tmp);
        }
      }
    }
  }
  
  cout << ans << endl;
}