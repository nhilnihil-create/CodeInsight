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

int N;
int C;
vector<int> s, t, c;

int solve()
{
  vector<vector<pii>> st(C);
  rep(i, N) st[c[i]].push_back({s[i], t[i]});
  rep(j, C) sort(all(st[j]));

  vector<pii> brks;
  rep(j, C)
  {
    int S, T;
    S = 0;
    T = 0;
    for (auto st_ : st[j])
    {
      int s_ = st_.first;
      int t_ = st_.second;
      if (s_ == T)
      {
        T = t_;
        continue;
      }

      if (T != 0)
        brks.push_back({T, 1});
      brks.push_back({S = s_, 0});
      T = t_;
    }
    if (T != 0)
      brks.push_back({T, 1});
  }
  sort(all(brks));

  int overlap = 0;
  int ans = 0;
  for (auto brk : brks)
  {
    if (brk.second == 0)
    {
      overlap++;
      chmax(ans, overlap);
    }
    else
      overlap--;
  }
  return ans;
}

void get_input()
{
  cin >> N >> C;
  s = vector<int>(N);
  t = vector<int>(N);
  c = vector<int>(N);
  rep(i, N)
  {
    cin >> s[i] >> t[i] >> c[i];
    c[i]--;
  }
}

int main()
{
  srand(time(0));
  cout << fixed << setprecision(15);

  get_input();
  cout << solve() << endl;
  return 0;
}
