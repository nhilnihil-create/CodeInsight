#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
 
#define repss(name, start, stop, step) for (int name = start; name < stop; name += step)
#define reps(name, start, stop) repss(name, start, stop, 1)
#define rep(name, stop) reps(name, 0, stop)
#define foreach(name, iterable) for (auto name = iterable.begin(); name != iterable.end(); name++)

using namespace std;
 
int main() {
  int N;
  cin >> N;

  int t;
  vector<int> A, B, C;
  rep(i, N) { cin >> t; A.push_back(t); }
  rep(i, N) { cin >> t; B.push_back(t); }
  rep(i, N) { cin >> t; C.push_back(t); }

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());

  long long ans = 0;
  for (auto Bi = B.begin(); Bi != B.end(); Bi++) {
      auto Ae = lower_bound(A.begin(), A.end(), *Bi);
      auto Cs = lower_bound(C.begin(), C.end(), *Bi + 1);
      ans += (Ae - A.begin()) * (C.end() - Cs);
  }

  cout << ans << endl;
}
