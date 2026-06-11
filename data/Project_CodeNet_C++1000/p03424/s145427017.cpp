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
  ll N;
  cin >> N;
  set<char> S;
  char c;
  for (int i = 0; i < N; i++) {
    cin >> c;
    S.insert(c);
  }
  if (S.size() == 3) {
    cout << "Three" << endl;
  } else {
    cout << "Four" << endl;
  }
  return 0;
}