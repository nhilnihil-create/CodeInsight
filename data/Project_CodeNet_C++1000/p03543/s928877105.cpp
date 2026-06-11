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
  string S;
  cin >> S;
  ll cnt = 0;
  for (int i = 0; i < S.length(); i++) {
    ll c = 1;
    int start = i;
    while (i + c < S.length() && S[i] == S[start + c]) {
      c++;
    }
    cnt = max(cnt, c);
  }
  if (cnt >= 3)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}