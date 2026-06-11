#include <bits/stdc++.h>
using namespace std;

// 区間[i, j)に水やりをする関数
// 戻り値は水やりをした回数
int water(vector<int> &hs, int i, int j) {
  // 対象がないときにresult = 200が返っちゃう
  if (i >= j) { return 0; }

  int result = 200;
  for (int p = i; p < j; p++) {
    result = min(result, hs[p]);
  }
  for (int p = i; p < j; p++) {
    hs[p] -= result;
  }
  return result;
}

int main(void) {
  int n;
  cin >> n;
  vector<int> hs(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> hs[i];
  }

  int result = 0;
  int head = 0;
  int tail = 0;

  for (int i = 0; i < 100 * 1000; i++) {
    while (hs[head] == 0) { head++; }
    tail = head + 1;
    while (hs[tail] != 0) { tail++; }

    // 区間[i, j)に対して水やり
    if (head > n) { break; }
    result += water(hs, head, tail);
  }

  cout << result << endl;

  return 0;
}