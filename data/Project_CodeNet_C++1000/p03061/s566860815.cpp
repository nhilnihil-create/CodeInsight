#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <bitset>
#include <complex>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <cassert>
#include <functional>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(...) ;
#else
#define debug(...) cerr << __LINE__ << " : " << #__VA_ARGS__ << " = " << _tostr(__VA_ARGS__) << endl;

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &v);

template<typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}

void _tostr_rec(ostringstream &oss) {
  oss << "\b\b \b";
}

template<typename Head, typename... Tail>
void _tostr_rec(ostringstream &oss, Head &&head, Tail &&... tail) {
  oss << head << ", ";
  _tostr_rec(oss, forward<Tail>(tail)...);
}

template<typename... T>
string _tostr(T &&... args) {
  ostringstream oss;
  int size = sizeof...(args);
  if (size > 1) oss << "{";
  _tostr_rec(oss, forward<T>(args)...);
  if (size > 1) oss << "}";
  return oss.str();
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010

// GCC __gcd(long long A, long long B)

ll gcd(ll a, ll b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

int main() {
  int N, A[SIZE];
  int L[SIZE], R[SIZE];

  cin >> N;

  for (int i = 0; i < N; i++) cin >> A[i];

  L[1] = A[0];
  for (int i = 1; i < N; i++) {
    L[i + 1] = gcd(L[i], A[i]);
  }

  R[N - 2] = A[N - 1];
  for (int i = N - 2; i > 0; i--) {
    R[i - 1] = gcd(R[i], A[i]);
  }

  int ans = max(R[0], L[N - 1]);

  for (int i = 0; i < N; i++) {
    ans = max(ans, (int)gcd(L[i], R[i]));
  }

  cout << ans << endl;

  return 0;
}