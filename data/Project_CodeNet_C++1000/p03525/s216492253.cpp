#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = pow(10, 9) + 7;
//const ll MOD = 998244353;
//const ll MOD = ;
ll mod(ll A, ll M) {return (A % M + M) % M;}
const ll INF = 1LL << 60;
template<class T> bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
ll divCeil(ll A, ll B) {return (A + (B - 1)) / B;}
ll myctoi(char C) {return C - '0';}
char myitoc(ll N) {return '0' + N;}
#define FINALANS(A) {cout << A << endl; exit(0);}

int main()
{
  ll N;
  cin >> N;
  map<ll, ll> mp;
  for (ll i = 0; i < N; i++)
  {
    ll D;
    cin >> D;
    mp[D]++;
  }

  vector<bool> d(25, false);
  d.at(0) = true, d.at(24) = true;
  bool isL = false;
  for (auto x : mp)
  {
    ll D = x.first, M = x.second;

    if (M >= 3)
      FINALANS(0);
    
    if (M == 2)
    {
      if (D == 0 || D == 12)
        FINALANS(0);
      
      d.at(D) = true, d.at(24 - D) = true;
    }
    else if (M == 1)
    {
      if (D == 0)
        FINALANS(0);

      d.at((isL) ? 24 - D : D) = true;
      isL = !isL;
    }
  }

  ll ans = INF;
  ll tmp = 0;
  for (ll i = 1; i < 25; i++)
  {
    if (d.at(i))
    {
      chmin(ans, i - tmp);
      tmp = i;
    }
  }

  cout << ans << endl;
}