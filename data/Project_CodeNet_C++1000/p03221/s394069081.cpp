#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  map<int, P> mp;
  map<P, string> targets;

  rep(i, 0, m) {
    int p, y;
    cin >> p >> y;
    P x = make_pair(p, y);
    mp[i] = x;

    stringstream ss;
    ss << setw(6) << setfill('0') << p;
    string sx = ss.str();
    targets[x] = sx;
  }

  int bef = 1, now = 0;
  for (auto target : targets) {
    if (bef == target.first.first)
      now++;
    else
      now = 1;

    stringstream ss;
    ss << setw(6) << setfill('0') << now;
    string sx = ss.str();
    targets[target.first] += sx;
    bef = target.first.first;
  }

  for (auto m : mp) {
    cout << targets[m.second] << endl;
  }
}
