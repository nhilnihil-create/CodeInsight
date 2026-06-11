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
  ll A, B, K;
  cin >> A >> B >> K;
  for (int i = 0; i < K; i++) {
    if (i % 2 == 0) {
      if (A % 2 == 1) {
        A--;
      }
      B += A / 2;
      A -= A / 2;
    } else {
      if (B % 2 == 1) {
        B--;
      }
      A += B / 2;
      B -= B / 2;
    }
  }
  cout << A << " " << B << endl;
  return 0;
}