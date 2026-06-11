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
  ll N, Q;
  string S;
  cin >> N >> Q >> S;
  vector<ll> accum(N, 0);
  for (int i = 1; i < S.size(); i++) {
    if (S[i - 1] == 'A' && S[i] == 'C') {
      accum[i] = accum[i - 1] + 1;
    } else {
      accum[i] = accum[i - 1];
    }
  }
  int l, r;
  for (int i = 0; i < Q; i++) {
    cin >> l >> r;
    cout << accum[r - 1] - accum[l - 1] << endl;
  }
  return 0;
}