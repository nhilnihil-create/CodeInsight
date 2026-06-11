#include <bits/stdc++.h>
using namespace std;

int max_index(const vector<int> &xs) {
  vector<int> ys(xs);
  vector<int>::iterator iter = max_element(ys.begin(), ys.end());
  return distance(ys.begin(), iter);
}

int change_count(int n, const vector<int> &xs, const vector<int> &ys) {
  int x_max_idx = max_index(xs);
  int y_max_idx = max_index(ys);

  int result = 0;
  if (x_max_idx != y_max_idx) {
    result += n / 2 - xs[x_max_idx];
    result += n / 2 - ys[y_max_idx];
  } else {
    vector<int> txs(xs);
    txs[x_max_idx] = 0;
    vector<int> tys(ys);
    tys[y_max_idx] = 0;

    result = min(
      change_count(n, txs, ys),
      change_count(n, xs, tys));
  }

  return result;
}

int main(void) {
  int n;
  cin >> n;
  vector<int> vs(n / 2);
  vector<int> ws(n / 2);
  for (int i = 0; i < n / 2; i++) {
    cin >> vs[i] >> ws[i];
  }

  // 数値と出現数のペアを取得しなきゃいけないので
  vector<int> v_count(100001);
  vector<int> w_count(100001);
  for (const int &v : vs) v_count[v]++;
  for (const int &w : ws) w_count[w]++;

  int result = change_count(n, v_count, w_count);
  
  cout << result << endl;
  return 0;
}