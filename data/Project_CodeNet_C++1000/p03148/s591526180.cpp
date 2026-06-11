

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;

int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> sushi(n);
  vector<ll> f(n + 1);
  unordered_map<int, int> um;
  rep(i, n) { cin >> sushi.at(i).second >> sushi.at(i).first; }
  sort(sushi.begin(), sushi.end(), greater<pair<int, int>>());
  // priority_queue<pair<int, int>, vector<pair<int, int>>,
  //                greater<pair<int, int>>>
  //     pq;

  ll sum = 0;
  rep(i, k) {
    int type = sushi.at(i).second;
    if (um.count(type)) {
      um.at(type) += 1;
    } else {
      um.emplace(type, 1);
    }
    sum += sushi.at(i).first;
    // pq.push(sushi.at(i));
  }
  f.at(um.size()) = sum + um.size() * um.size();

  int from = k - 1;
  int to = k;

  ll maxval = f.at(um.size());
  if (n == k) {
    cout << maxval << endl;
    return 0;
  }
  while (true) {
    int ftype = sushi.at(from).second;
    int fpt = sushi.at(from).first;
    int ttype = sushi.at(to).second;
    int tpt = sushi.at(to).first;
    bool fstop = true;
    bool tstop = true;
    if (um.at(ftype) == 1) {
      from--;
      fstop = false;
    }
    if (um.count(ttype) != 0) {
      to++;
      tstop = false;
    }
    if (fstop && tstop) {
      int usize = um.size();
      f.at(usize + 1) =
          f.at(usize) - fpt + tpt - usize * usize + (usize + 1) * (usize + 1);
      um.emplace(ttype, 1);
      maxval = max(f.at(usize + 1), maxval);
      um.at(ftype) -= 1;
      from--;
      to++;
    }
    if (from == -1 || to == n) {
      break;
    }
  }
  cout << maxval << endl;
  return 0;
}
