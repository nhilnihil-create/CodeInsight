#include <iostream>
#include <algorithm>
using namespace std;
long long F[100][10];
long long P[100][11];
int main(void) {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> F[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= 10; j++) {
      cin >> P[i][j];
    }
  }

  long long ans = -9223372036854775808;
  // 営業中の時間帯bit1
  // 営業なしはなしなので下限値は1
  for (unsigned int op = 1; op < (1<<10); op++) {
    long long profit = 0;
    for (int store_num = 0; store_num < N; store_num++) {
      unsigned int op_count = 0;
      for (unsigned int time_zone = 0; time_zone < 10; time_zone++) {
        // お姉ちゃんが店を開かない場合は営業利益を計算しない
        if ((op & (1<<time_zone)) == 0) continue;

        if (F[store_num][time_zone]==1) op_count++;
      }
      profit += P[store_num][op_count];
    }
    ans = max(ans, profit);
  }
  cout << ans << endl;
  return 0;
}
