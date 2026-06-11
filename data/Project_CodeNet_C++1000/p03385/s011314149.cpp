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
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  if ("abc" == s) {
    cout << "Yes" << endl;
  } else
    cout << "No" << endl;
  return 0;
}