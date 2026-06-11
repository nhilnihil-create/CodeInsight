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
  int A, B, K;
  cin >> A >> B >> K;
  int cnt = 0;
  for (int i = min(A, B); i >= 1; i--) {
    if (A % i == 0 && B % i == 0) {
      K--;
      if (K == 0) {
        cout << i << endl;
        return 0;
      }
    }
  }

  return 0;
}
