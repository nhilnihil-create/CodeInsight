#include <iostream>
#include <vector>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int N, x;
  cin >> N >> x;
  vector<int> a(N);
  REP(i, N) cin >> a.at(i);
  sort(a.begin(), a.end());
  int cnt = 0;
  REP(i, N) {
    if (i == N-1 && a.at(i) != x) break;
    x -= a.at(i);
    if (x < 0) break;
    cnt++;
  }
  cout << cnt << endl;
  return 0;
}