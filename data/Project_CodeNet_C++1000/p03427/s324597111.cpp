#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define blank(ans) cout << (ans) << " ";
#define mp(p, q) make_pair(p, q)
#define mt(p, q, r) make_tuple(p, q, r)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;

typedef vector<ll> vll;
typedef vector<ld> vd;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<str> vs;
typedef vector<vector<ll>> vvll;
typedef vector<vector<ld>> vvd;
typedef vector<vector<bool>> vvb;
typedef vector<vector<char>> vvc;
typedef vector<vector<str>> vvs;
typedef vector<pair<ll, ll>> vpll;
typedef vector<tuple<ll, ll, ll>> vtlll;

const ld PI = acos(-1.0);
const ll MAX = 9000000000000000000;
const ll MIN = -9000000000000000000;
const ld DMAX = 4500;
const ld DMIN = -4500;
const ll MOD = 1000000007;

template <typename T>
void fin(T a)
{
  cout << a << endl;
  exit(0);
}

//実行部
void Main()
{
  ll n; cin >> n;
  vll a;
  while (n)
  {
    a.pb(n % 10);
    n /= 10;
  }
  ll ans = 0, flag  = 0;
  rep(i, a.size() - 1)
  {
    if(a[i] != 9)
    {
      flag = 1;
    }
    ans += 9;
  }
  if(flag == 1)
  ans += (a[a.size() - 1] - 1);
  else
  ans += (a[a.size() - 1]);
  fin(ans);
}

//前処理
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(20); //高精度少数表示
  Main();
  return 0;
}

/*
//test時
  g++ test.cpp -o test;./test
*/
