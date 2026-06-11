#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define dump(x) cerr << #x << "=" << x << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int A, B, C;
  cin >> A >> B >> C;

  cout << min(B / A, C) << endl;

  return 0;
}