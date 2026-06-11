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
  string S;
  ll K;
  cin >> S >> K;
  ll not_one_id;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] != '1') {
      not_one_id = i;
      break;
    }
  }
  if (K == 1) {
    cout << S[0] << endl;
  } else if (K < not_one_id + 1) {
    cout << 1 << endl;
  } else {
    cout << S[not_one_id] << endl;
  }
  return 0;
}