#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
  int N, K;
  string S;
  cin >> N >> K;
  cin >> S;

  // 奇数が立ち、偶数が逆立ち
  vector <int> sum;

  // 計算の都合上、最初に0を入れる
  sum.push_back(0);

  char pre_updown = '0'; // 0:stand, 1:updown
  int continue_cnt = 0;

  for (int i = 0; i < N; i++) {
    char updown = S[i];
    if (updown != pre_updown) {
      sum.push_back(sum[sum.size()-1] + continue_cnt);

      pre_updown = updown;
      continue_cnt = 1;
    } else {
      continue_cnt += 1;
    }
  }

  // last
  sum.push_back(sum[sum.size()-1] + continue_cnt);

  // 計算の都合上、最後に+0を入れる
  sum.push_back(sum[sum.size()-1]+0);

  int ans = 0;

  for (int st = 0; st < sum.size(); st+=2) {
    int en = min(st+K+K, (int)sum.size()-1);
    ans = max(ans, sum[en]-sum[max(st-1,0)]);
  }
  cout << ans << endl;
  return 0;
}
