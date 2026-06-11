#include <bits/stdc++.h>
using namespace std;

//////////////////////////////   Begin Macros

#define all(x) (x).begin(), (x).end()
#define rep(i, N) for (int i = 0; i < (int)(N); i++)
#define reprev(i, N) for (int i = (int)(N)-1; i >= 0; i--)
#define rep1(i, N) for (int i = 1; i <= (int)(N); i++)
#define rep1rev(i, N) for (int i = (int)(N); i >= 0; i--)
#define forbe(i, b, e) for (int i = (b); i < (e); i++)
#define forberev(i, b, e) for (int i = (e)-1; i >= (b); i--)
#define forfl(i, f, l) for (int i = (f); i <= (l); i++)
#define forflrev(i, f, l) for (int i = (l); i >= (f); i--)
using ll = long long int;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

template <typename T>
bool chmax(T &m, const T q)
{
  if (m < q)
  {
    m = q;
    return true;
  }
  else
    return false;
}
template <typename T>
bool chmin(T &m, const T q)
{
  if (m > q)
  {
    m = q;
    return true;
  }
  else
    return false;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return {l.first + r.first, l.second + r.second}; }
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return {l.first - r.first, l.second - r.second}; }
template <typename T>
pair<T, T> operator*(const pair<T, T> &l, const T &r) { return {l.first * r, l.second * r}; }
template <typename T>
pair<T, T> operator/(const pair<T, T> &l, const T &r) { return {l.first / r, l.second / r}; }
template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
  for (auto &v : vec)
    is >> v;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
  os << "[";
  for (auto v : vec)
    os << v << ",";
  os << "]";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &vec)
{
  os << "deq[";
  for (auto v : vec)
    os << v << ",";
  os << "]";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &vec)
{
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &vec)
{
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &vec)
{
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &vec)
{
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &pa)
{
  os << "(" << pa.first << "," << pa.second << ")";
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const map<TK, TV> &mp)
{
  os << "{";
  for (auto v : mp)
    os << v.first << "=>" << v.second << ",";
  os << "}";
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp)
{
  os << "{";
  for (auto v : mp)
    os << v.first << "=>" << v.second << ",";
  os << "}";
  return os;
}

template <typename T>
void reset(vector<T> &v, const T reset_to)
{
  for (auto &x : v)
    x = reset_to;
}
inline int popcount(const unsigned int x) { return __builtin_popcount(x); }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

ll nC2(ll n)
{
  return n * (n - 1) / 2;
}

const int intinf = numeric_limits<int>::max();
const ll llinf = numeric_limits<ll>::max();
const pii udlr[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

//////////////////////////////   End Macros

void solve()
{
  int N;
  int C;
  cin >> N >> C;
  vector<int> s(N), t(N), c(N);
  c = vector<int>(N);
  rep(i, N)
  {
    cin >> s[i] >> t[i] >> c[i];
    c[i]--;
  }

  vector<vector<pii>> st(C);
  int maxst = 200001;
  vector<vector<int>> schedule(C, vector<int>(maxst, 0));
  rep(i, N)
  {
    forfl(j, s[i] * 2 - 1, t[i] * 2)
    {
      schedule[c[i]][j]++;
    }
  }

  vector<int> overlaps(maxst, 0);
  rep(j, maxst)
  {
    rep(k, C) if (schedule[k][j] > 0) overlaps[j]++;
  }
  int ans = *max_element(all(overlaps));
  cout << ans << endl;
}

int main()
{
  srand(time(0));
  cout << fixed << setprecision(15);

  solve();
  return 0;
}
