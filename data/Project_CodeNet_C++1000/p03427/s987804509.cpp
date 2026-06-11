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
  string N;
  cin >> N;
  ll cand1 = N[0] - '0';
  for (int i = 1; i < N.length(); i++) {
    cand1 += N[i] - '0';
  }
  ll cand2 = max(N[0] - '0' - 1, 0);
  for (int i = 1; i < N.length(); i++) {
    cand2 += 9;
  }
  cout << max(cand1, cand2) << endl;
  return 0;
}