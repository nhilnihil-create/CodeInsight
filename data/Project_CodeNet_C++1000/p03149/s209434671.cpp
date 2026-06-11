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
  vector<ll> N(4);
  cin >> N[0] >> N[1] >> N[2] >> N[3];
  sort(N.begin(), N.end());
  if (N[0] == 1 && N[1] == 4 && N[2] == 7 && N[3] == 9)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}