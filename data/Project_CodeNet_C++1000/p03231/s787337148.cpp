#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int main() {
  ll N, M;
  string S, T;
  cin >> N >> M >> S >> T;
  ll lcm_nm = lcm(N, M);
  ll gcd_nm = gcd(N, M);
  ll n = N / gcd_nm;
  ll m = M / gcd_nm;
  ll s_i, t_i;
  bool fail_flag = false;
  for (int i = 0; i < gcd_nm; i++) {
    if (S[n * i] != T[m * i]) {
      fail_flag = true;
      break;
    }
  }
  if (fail_flag) {
    cout << -1 << endl;
  } else {
    cout << lcm_nm << endl;
  }
  return 0;
}