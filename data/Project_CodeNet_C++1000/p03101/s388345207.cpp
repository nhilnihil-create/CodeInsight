#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long long int lli;
typedef unsigned long long int ull;
typedef long double ld;
typedef string str;

typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<str> vs;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<char>> vvc;
typedef vector<vector<str>> vvs;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rrep(i, n) for (ll i = 1; i <= (n); ++i)
#define fin(ans) cout << (ans) << endl;
#define mp(p, q) make_pair(p, q)
//３つ以上の値をセットに(3より多いときはカッコ内を増やす)\
sort -> p -> q -> r
#define mt(p, q, r) make_tuple(p, q, r)
#define all(a) a.begin(), a.end()

template <typename T>
void V(T &n)
{
  for (ll i = 0; i < n.size(); i++)
  {
    cin >> n[i];
  }
}

template <typename T, typename U>
void V2(T &n, U &m)
{
  for (ll i = 0; i < n.size(); i++)
  {
    cin >> n[i] >> m[i];
  }
}

template <typename T>
void Sort(T &n, ll a = 0, ll b = 0)
{
  if (b == 0)
  {
    return (sort(n.begin() + a, n.end()));
  }
  else
  {
    return (sort(n.begin() + a, n.begin() + b));
  }
}

//配列を反転
template <typename T>
void Reve(T &n, ll a = 0, ll b = 0)
{
  if (b == 0)
  {
    return (reverse(n.begin() + a, n.end()));
  }
  else
  {
    return (reverse(n.begin() + a, n.begin() + b));
  }
}

template <typename T>
void Down(T &n, ll a = 0, ll b = 0)
{
  if (b == 0)
  {
    return (sort(n.begin() + a, n.end(), greater<ll>()));
  }
  else
  {
    return (sort(n.begin() + a, n.begin() + b, greater<ll>()));
  }
}

  void Main()
  {
    ll H, W, h , w; cin >> H >> W >> h >> w;
    fin(H * W - (h * W + w * H) + h * w)
  }

  int main()
  {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20); //高精度少数表示
    Main();
    return 0;
  }