#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define all(f,c,...) (([&](decltype((c)) cccc) { return (f)(begin(cccc), end(cccc), ## __VA_ARGS__); })(c))

int main() {
  int N; cin >> N;

  map<int, int> count;
  rep(i, N) {
    int n = i+1;
    for (int j = 2; j * j <= n; ++j) {
      while (n % j == 0) {
        n /= j;
        ++count[j];
      }
    }
    if (n > 1)
      ++count[n];
  }
  vector<int> v;
  for (const auto& e : count) v.push_back(e.second);
  all(reverse, v);

  int two = v.end() - all(lower_bound, v, 3-1);
  int four = v.end() - all(lower_bound, v, 5-1);

  int ans = four * (four-1) * (two - 2) / 2;

  int fst = v.end() - all(lower_bound, v, 3-1);
  int snd = v.end() - all(lower_bound, v, 25-1);
  ans += (fst-1) * snd;

  fst = v.end() - all(lower_bound, v, 5-1);
  snd = v.end() - all(lower_bound, v, 15-1);
  ans += (fst-1) * snd;

  fst = v.end() - all(lower_bound, v, 75-1);
  ans += fst;

  cout << ans << endl;

  return 0;
}
