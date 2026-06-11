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
  ll N = 3;
  vector<vector<char>> C(N, vector<char>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> C[i][j];
    }
  }
  cout << C[0][0] << C[1][1] << C[2][2] << endl;
  return 0;
}