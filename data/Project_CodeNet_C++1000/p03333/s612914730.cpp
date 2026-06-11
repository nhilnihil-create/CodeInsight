#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <vector>
#define REP(i, n) for (long(i) = 0; (i) < (n); (i)++)
#define REPI(i, a, b) for (long(i) = (a); (i) < (b); (i)++)
#define uniq(v) (v).erase(std::unique((v).begin(), (v).end()), (v).end())
constexpr long MOD = 998244353l;
long gcd(long a, long b) { return b % a ? gcd(b % a, a) : a; }
long lcm(long a, long b) { return a / gcd(a, b) * b; }
using namespace std;
using P = pair<long, long>;
using VP = deque<P>;

int main() {
  long n;
  cin >> n;
  VP ls, rs;
  long maxDistFromStartRight = -1;
  long maxDistIndRight = -1;
  long maxDistFromStartLeft = -1;
  long maxDistIndLeft = -1;
  REP(i, n) {
    long l, r;
    cin >> l >> r;
    ls.push_back(P(l, i));
    rs.push_back(P(r, i));
    if (l > 0) {
      if (l >= maxDistFromStartRight) {
        maxDistFromStartRight = l;
        maxDistIndRight = i;
      }
    }
    if (r < 0) {
      if (-r > maxDistFromStartLeft) {
        maxDistFromStartLeft = -r;
        maxDistIndLeft = i;
      }
    }
  }
  if (maxDistIndLeft == -1 && maxDistIndRight == -1) {
    cout << 0 << endl;
    return 0;
  }

  vector<bool> used(n, false);

  long cur = 0;
  long ans = 0;
  sort(ls.begin(), ls.end());
  sort(rs.begin(), rs.end());
  VP rs2(rs);
  VP ls2(ls);
  if (maxDistIndRight != -1) {
    ans += maxDistFromStartRight;
    cur = maxDistFromStartRight;
    used[maxDistIndRight] = true;
    ls.pop_back();
    while (1) {
      // first go to smallest right
      while (rs.size() && used[rs.front().second]) {
        rs.pop_front();
      }
      if (rs.empty()) {
        break;
      }
      if (cur - rs.front().first < 0) {
        break;
      }
      ans += cur - rs.front().first;
      cur = rs.front().first;
      used[rs.front().second] = true;
      rs.pop_front();

      // then go to largest left
      while (ls.size() && used[ls.back().second]) {
        ls.pop_back();
      }
      if (ls.empty()) {
        break;
      }
      if (ls.back().first - cur < 0) {
        break;
      }
      ans += ls.back().first - cur;
      cur = ls.back().first;
      used[ls.back().second] = true;
      ls.pop_back();
    }
  }

  long realans = ans + abs(cur);

  if (maxDistIndLeft != -1) {
    REP(i, n) { used[i] = false; }
    ls = VP(ls2);
    rs = VP(rs2);
    cur = 0;
    ans = 0;
    ans += maxDistFromStartLeft;
    cur = -maxDistFromStartLeft;
    used[maxDistIndLeft] = true;
    rs.pop_front();
    while (1) {
      // first go to largest left
      while (ls.size() && used[ls.back().second]) {
        ls.pop_back();
      }
      if (ls.empty()) {
        break;
      }
      if (ls.back().first - cur < 0) {
        break;
      }
      ans += ls.back().first - cur;
      cur = ls.back().first;
      used[ls.back().second] = true;
      ls.pop_back();

      // then go to smallest right
      while (rs.size() && used[rs.front().second]) {
        rs.pop_front();
      }
      if (rs.empty()) {
        break;
      }
      if (cur - rs.front().first < 0) {
        break;
      }
      ans += cur - rs.front().first;
      cur = rs.front().first;
      used[rs.front().second] = true;
      rs.pop_front();
    }
  }

  cout << max(realans, ans + abs(cur)) << endl;
}