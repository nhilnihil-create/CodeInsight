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
int cand1[10] = {'M', 'M', 'M', 'M', 'M', 'M', 'A', 'A', 'A', 'R'};
int cand2[10] = {'A', 'A', 'A', 'R', 'R', 'C', 'R', 'R', 'C', 'C'};
int cand3[10] = {'R', 'C', 'H', 'C', 'H', 'H', 'C', 'H', 'H', 'H'};

int main() {
  ll N;
  cin >> N;
  string s;
  map<char, ll> march_cnt;
  march_cnt['M'] = 0;
  march_cnt['A'] = 0;
  march_cnt['R'] = 0;
  march_cnt['C'] = 0;
  march_cnt['H'] = 0;
  for (size_t i = 0; i < N; i++) {
    cin >> s;
    if (s[0] == 'M' || s[0] == 'A' || s[0] == 'R' || s[0] == 'R' ||
        s[0] == 'C' || s[0] == 'H') {
      march_cnt[s[0]]++;
    }
  }
  ll ans = 0;
  ll n = march_cnt.size();
  if (n >= 3) {
    for (int i = 0; i < 10; i++) {
      ans += march_cnt[cand1[i]] * march_cnt[cand2[i]] * march_cnt[cand3[i]];
    }
  }
  cout << ans << endl;
  return 0;
}