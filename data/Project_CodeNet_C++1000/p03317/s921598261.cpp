#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
typedef long long ll;
using namespace std;
const int MOD = 1000000007;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }

int N, K;
vector<int> A;

int main() {
  while (cin >> N >> K) {
    A.resize(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    int res = 0;
    int right = 0;
    while (true) {
      if (res == 0) right += K;
      else right += K-1;
      ++res;

      if (right >= N) break;
    }
    cout << res << endl;
  }
}