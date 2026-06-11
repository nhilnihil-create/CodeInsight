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
  vector<int> L(N);
  int m = 0, tot = 0;
  rep(i, 0, N) {
    cin >> L[i];
    m = max(m, L[i]);
    tot += L[i];
  }

  tot -= m;
  if (m < tot)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
