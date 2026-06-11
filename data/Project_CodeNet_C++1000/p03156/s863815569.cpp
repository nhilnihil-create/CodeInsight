#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#define MOD (1000000007l)
#define rep(i, n) for(long i = 0; i < n; i++)

using namespace std;

void solve() {
  long N, A, B;
  cin >> N >> A >> B;
  unordered_map<long, long> mp;
  rep(i, N) {
    long p;
    cin >> p;
    if (p <= A) mp[1]++;
    else if (p<= B) mp[2]++;
    else mp[3]++;
  }
  cout << min(mp[1], min(mp[2], mp[3])) << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(12);
  solve();
  return 0;
}
