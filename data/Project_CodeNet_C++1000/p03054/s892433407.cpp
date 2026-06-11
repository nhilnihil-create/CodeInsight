#pragma region Macros
#include <bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using multiInt = boost::multiprecision::cpp_int;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
template <typename Q_type>
using smaller_queue = priority_queue<Q_type, vector<Q_type>, greater<Q_type>>;

constexpr int MOD_TYPE = 2;
constexpr ll MOD = (MOD_TYPE == 1 ? (ll)(1e9 + 7) : 998244353);
constexpr int INF = (int)1e9;
constexpr ll LINF = (ll)4e18;
constexpr ld PI = acos(-1.0);
constexpr ld EPS = 1e-11;
constexpr int Dx[] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
constexpr int Dy[] = {1, -1, 0, 0, -1, -1, 1, 1, 0};

#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << "\n"
#define Yes(n) cout << ((n) ? "Yes" : "No") << "\n"
#define possible(n) cout << ((n) ? "possible" : "impossible") << "\n"
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << "\n"
#define Yay(n) cout << ((n) ? "Yay!" : ":(") << "\n"
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << "\n";

#pragma endregion

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(30) << setiosflags(ios::fixed);

  int h, w, n, sr, sc;
  string s, t;
  cin >> h >> w >> n;
  cin >> sr >> sc >> s >> t;
  int L = sc, R = sc;
  int L_cnt = 0, R_cnt = 0;
  rep(i, n)
  {
    if (s[i] == 'R')
    {
      R++;
    }
    else if (s[i] == 'L')
    {
      L--;
    }

    if (L <= 0)
    {
      if (R_cnt > 0)
      {
        R_cnt--;
        L++, R++;
      }
      else
      {
        YES(false);
        return 0;
      }
    }
    else if (R > w)
    {
      if (L_cnt > 0)
      {
        L_cnt--;
        L--, R--;
      }
      else
      {
        YES(false);
        return 0;
      }
    }

    if (t[i] == 'L')
    {
      if (L == R)
      {
        if (L - L_cnt > 1)
          L_cnt++;
      }
      else
      {
        R--;
      }
    }
    else if (t[i] == 'R')
    {
      if (L == R)
      {
        if (R + R_cnt < w)
          R_cnt++;
      }
      else
      {
        L++;
      }
    }
  }
  L = R = sr;
  L_cnt = R_cnt = 0;
  rep(i, n)
  {
    if (s[i] == 'D')
    {
      R++;
    }
    else if (s[i] == 'U')
    {
      L--;
    }
    if (L <= 0)
    {
      if (R_cnt > 0)
      {
        R_cnt--;
        L++, R++;
      }
      else
      {
        YES(false);
        return 0;
      }
    }
    else if (R > h)
    {
      if (L_cnt > 0)
      {
        L_cnt--;
        L--, R--;
      }
      else
      {
        YES(false);
        return 0;
      }
    }

    if (t[i] == 'U')
    {
      if (L == R)
      {
        if (L - L_cnt > 1)
          L_cnt++;
      }
      else
      {
        R--;
      }
    }
    else if (t[i] == 'D')
    {
      if (L == R)
      {
        if (R + R_cnt < h)
          R_cnt++;
      }
      else
      {
        L++;
      }
    }
  }
  YES(true);
  return 0;
}
