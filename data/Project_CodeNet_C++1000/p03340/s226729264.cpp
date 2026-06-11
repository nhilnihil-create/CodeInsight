#pragma region

#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for (register int i = (begin); i < (end); i++)
#define IFOR(i, begin, end) for (register int i = (end)-1; i >= (begin); i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define MOD 1000000007
#define debug(x) cerr << #x << " = " << (x) << " (line: " << __LINE__ << ") " << endl;
typedef long long ll;
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "vec[ ";
  REP(i, vec.size())
  i == 0 ? os << vec[i] : os << ", " << vec[i];
  os << " ]";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &deq) {
  os << "deq[ ";
  REP(i, deq.size())
  i == 0 ? os << deq[i] : os << ", " << deq[i];
  os << " ]";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &set) {
  os << "{ ";
  for (auto &&s : set) &s == &(*set.begin()) ? os << s : os << ", " << s;
  os << " }";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &set) {
  os << "{ ";
  for (auto &&s : set) &s == &(*set.begin()) ? os << s : os << ", " << s;
  os << " }";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &set) {
  os << "{ ";
  for (auto &&s : set) &s == &(*set.begin()) ? os << s : os << ", " << s;
  os << " }";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &set) {
  os << "{ ";
  for (auto &&s : set) &s == &(*set.begin()) ? os << s : os << ", " << s;
  os << " }";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const map<TK, TV> &m) {
  os << "{ ";
  for (auto &&k : m) &k == &(*m.begin()) ? os << k.first << " => " << k.second : os << ", " << k.first << " => " << k.second;
  os << " }";
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const unordered_map<TK, TV> &m) {
  os << "{ ";
  for (auto &&k : m) &k == &(*m.begin()) ? os << k.first << " => " << k.second : os << ", " << k.first << " => " << k.second;
  os << " }";
  return os;
}

#pragma endregion
#pragma region

#define out(x) cout << (x) << '\n';

ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}

bool isPrime(ll a) {
  if (a == 2) return true;
  if (a < 2 || a % 2 == 0) return false;
  int b = sqrt(a);
  for (register int i = 3; i <= b; i += 2)
    if (b % i == 0) return false;
  return true;
}

#pragma endregion
#define INF 2147483647

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(16);

  ll N;
  cin >> N;
  vector<int> A(N);
  cin >> A;

  int r = 0;
  int x = 0;
  ll ans = 0;
  REP(l, N) {
    while (r < N && (x ^ A[r]) == x + A[r]) {
      x ^= A[r];
      r++;
    }
    ans += r - l;
    x ^= A[l];
  }
  out(ans);
}
