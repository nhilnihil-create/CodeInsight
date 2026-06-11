#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#define ll long long
using namespace std;
const int MOD = 1000000007;
const long long INF = 1LL << 60;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  vector<int> start(26, -1);
  vector<int> goal(26, -1);
  for (ll i = 0; i < s.size(); i++) {
    int a = s[i] - 'a';
    int b = t[i] - 'a';
    if (start[a] != -1 || goal[b] != -1) {
      if (start[a] != b || goal[b] != a) {
        cout << "No" << endl;
        return 0;
      }
    } else {
      start[a] = b;
      goal[b] = a;
    }
  }
  cout << "Yes" << endl;
}