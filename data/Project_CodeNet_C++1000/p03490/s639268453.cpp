#include <bits/stdc++.h>
using namespace std;

const int B = 8000;

int N;
int xs[2];
char buf[114514];
bool dp[2][2][2*B+1];
vector<int> nums[2];

int main() {
  scanf("%s", buf);
  N = strlen(buf);
  for (int k=0; k<2; k++) {
    scanf("%d", &xs[k]);
  }

  int t = 0;
  for (; t<N; t++) {
    if (buf[t] == 'T') break;
    xs[0]--;
  }

  int grp = 0;
  int cnt = 0;
  for (; t<N; t++) {
    if (buf[t] == 'T') {
      if (cnt > 0) nums[grp].emplace_back(cnt);
      grp ^= 1;
      cnt = 0;
    } else {
      ++cnt;
    }
  }
  if (cnt > 0) nums[grp].emplace_back(cnt);

  for (int k=0; k<2; k++) {
    int src = 0;
    int dst = 1;

    dp[k][src][B] = true;
    for (int d : nums[k]) {
      for (int j=-B; j<=B; j++) {
        if (!dp[k][src][B+j]) continue;
        if (-B <= j-d) dp[k][dst][B+j-d] = true;
        if (j+d <= B) dp[k][dst][B+j+d] = true;
      }

      swap(dst, src);
      fill(dp[k][dst], dp[k][dst]+2*B+1, false);
    }

    if (xs[k] < -B || B < xs[k] || !dp[k][src][B+xs[k]]) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
}
