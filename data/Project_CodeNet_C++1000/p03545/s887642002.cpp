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
char op[2] = {'+', '-'};

int calc(int x, int y, char op) {
  if (op == '+')
    return x + y;
  else
    return x - y;
}

int main() {
  string exp;
  cin >> exp;
  int A = exp[0] - '0', B = exp[1] - '0', C = exp[2] - '0', D = exp[3] - '0';
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        if (calc(calc(calc(A, B, op[i]), C, op[j]), D, op[k]) == 7) {
          cout << A << op[i] << B << op[j] << C << op[k] << D << "=7" << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}