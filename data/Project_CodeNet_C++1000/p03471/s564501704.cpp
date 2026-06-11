/*
日本でよく使われる紙幣は、10000円札、5000円札、1000円札です。以下、「お札」とはこれらのみを指します。

青橋くんが言うには、彼が祖父から受け取ったお年玉袋にはお札が
N枚入っていて、合計でY円だったそうですが、嘘かもしれません。
このような状況がありうるか判定し、ありうる場合はお年玉袋の中身の候補を一つ見つけてください。なお、彼の祖父は十分裕福であり、お年玉袋は十分大きかったものとします。
*/

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Y;
  int yen10000, yen5000, yen1000;
  bool flag = false;
  cin >> N >> Y;

  for (int i = 0; i <= N; i++) {
    yen10000 = 10000 * i;
    for (int j = 0; j <= N - i; j++) {
      yen5000 = 5000 * j;
      yen1000 = 1000 * (N - i - j);
      if (yen10000 + yen5000 + yen1000 == Y) {
        cout << i << " " << j << " " << N - i - j << endl;
        flag = true;
        break;
      }
    }
    if (flag) break;
  }
  if (!flag) cout << "-1 -1 -1" << endl;
}