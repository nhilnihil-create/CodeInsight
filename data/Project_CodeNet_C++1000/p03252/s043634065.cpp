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
  string S, T;
  cin >> S >> T;
  map<char, char> S2T, T2S;
  bool fail_flag = false;
  for (int i = 0; i < S.length(); i++) {
    if (S2T.find(S[i]) == S2T.end()) {
      S2T[S[i]] = T[i];
    } else if (S2T[S[i]] != T[i]) {
      fail_flag = true;
      break;
    }
    if (T2S.find(T[i]) == T2S.end()) {
      T2S[T[i]] = S[i];
    } else if (T2S[T[i]] != S[i]) {
      fail_flag = true;
      break;
    }
  }
  string ans = "Yes";
  if (fail_flag) {
    ans = "No";
  }
  cout << ans << endl;
  return 0;
}