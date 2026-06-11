#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;
using GraphI = vector<vector<int>>;
using GraphC = vector<vector<char>>;
using pint = pair<int, int>;

const int INF = 1001001001;

int main() {
  int N;
  cin >> N;
  vector<int> p(N);
  int m = 0, tot = 0;
  rep(i, 0, N) {
    cin >> p[i];
    tot += p[i];
    m = max(m, p[i]);
  }
  tot -= (m / 2);
  cout << tot << endl;
  return 0;
}
