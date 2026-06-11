#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define uli unsigned long long int
#define rep(i, m, n) for (lli i = m; i < (n); i++)
#define repe(i, m, n) for (lli i = m; i <= (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) ((lli)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define _GLIBCXX_DEBUG
const lli INF = 2147483647;
const lli MINF = -2147483648;
const lli LINF = 9223372036854775807;
const lli MOD = 1000000007; //10^9+7
const double PI = acos(-1);
#define SORT(n) sort(n.begin(), n.end())
#define SORTR(n) sort(n.begin(), n.end(), greater<int>())
#define REV(n) reverse(n.begin(), n.end())
#define pb push_back
#define eb emplace_back
#define mp make_pair
#pragma GCC optimize("Ofast")
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vlli = vector<lli>;
using vvli = vector<vlli>;
using vs = vector<string>;
using vvs = vector<vs>;
using vb = vector<bool>;
using vvb = vector<vb>;
using ll = long long;
// vector入力
template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
  for (T &x : vec)
    is >> x;
  return is;
}
// vector出力
template <typename T>
ostream &operator<<(ostream &os, vector<T> &vec)
{
  // os << '{';
  for (int i = 0; i < vec.size(); i++)
  {
    os << vec[i] << (i + 1 == vec.size() ? "" : "");
  }
  // os << '}';
  return os;
}
// aよりもbが大きいならばaをbで更新する(更新されたならばtrueを返す)
template <typename T>
bool chmax(T &a, const T &b)
{
  if (a < b)
  {
    a = b; // aをbで更新
    return true;
  }
  return false;
}
// aよりもbが小さいならばaをbで更新する(更新されたならばtrueを返す)
template <typename T>
bool chmin(T &a, const T &b)
{
  if (a > b)
  {
    a = b; // aをbで更新
    return true;
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  lli k, a, b, c, h, n, w, ans = 1, count = 1, coin = 0;
  string s, t;
  vector<pair<string, pair<lli, lli>>> pr;
  cin >> k >> a >> b;

  if (b - a <= 2 || k < a - 1)
  {
    ans += k;
    cout << ans << endl;
    return 0;
  }
  else
  {
    ans = a;
    k -= a - 1;
    if (k % 2 == 1)
    {
      ans++;
      k--;
    }
    ans += (b - a) * (k / 2);
    cout << ans << endl;
  }
}