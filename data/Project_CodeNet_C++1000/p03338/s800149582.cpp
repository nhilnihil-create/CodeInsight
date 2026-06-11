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
  string S;
  cin >> N >> S;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    set<char> s1;
    for (int j = 0; j < i; j++) {
      s1.insert(S[j]);
    }
    int cnt = 0;
    set<char> s2;
    for (int j = i; j < N; j++) {
      if (s1.find(S[j]) != s1.end() && s2.find(S[j]) == s2.end()) {
        cnt++;
      }
      s2.insert(S[j]);
    }
    ans = max(cnt, ans);
  }
  cout << ans << endl;
  return 0;
}