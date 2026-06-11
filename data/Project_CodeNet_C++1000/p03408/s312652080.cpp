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

int main() {
  ll N, M;
  cin >> N;
  map<string, int> blue, red;
  vector<string> s(N);
  for (int i = 0; i < N; i++) {
    cin >> s[i];
    blue[s[i]]++;
  }
  cin >> M;
  vector<string> t(M);
  for (int i = 0; i < M; i++) {
    cin >> t[i];
    red[t[i]]++;
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans = max(ans, blue[s[i]] - red[s[i]]);
  }
  cout << ans << endl;
  return 0;
}