#include <bits/stdc++.h>
#define lli long long int
#define uli unsigned long long int
#define rep(i, m, n) for (lli i = m; i < (n); i++)
#define repe(i, m, n) for (lli i = m; i <= (n); i++)
#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) ((lli)(x).size())
#define MAX(x) *max_element(ALL(x))
#define INF 1000000000000 //10^12
#define MOD 10000007      //10^9+7
#define SORT(n) sort(n.begin(), n.end())
#define SORTR(n) sort(n.begin(), n.end(), greater<int>())
#define REV(n) reverse(n.begin(), n.end())
#define Vec(K, L, N, S) vector<L> K(N, S)
#define root sqrt
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vs = vector<string>;
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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  lli d, e, f, h, k, n, w, ans = 0, count = 0;
  string s, t;
  cin >> n;
  vector<lli> a(n), b(n + 1, 0);
  map<lli, lli> c;
  cin >> a;
  rep(i, 0, n)
  {
    b[i + 1] = b[i] + a[i];
  }
  rep(i, 0, n + 1)
  {
    c[b[i]]++;
  }
  for (auto it : c)
  {
    lli num = it.second; // it.first が it.second 個ある
    ans += num * (num - 1) / 2;
  }
  cout << ans << endl;
}