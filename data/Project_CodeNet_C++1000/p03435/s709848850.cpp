#include <bits/stdc++.h>
using namespace std;

#define println(msg) cout << msg << endl
#define yes_or_no(flag) if (flag) { println("Yes"); } else { println("No"); }
#define sort_vec(vec) sort(vec.begin(), vec.end())
#define rsort_vec(vec) sort(vec.rbegin(), vec.rend()) // greater<int>()

int main() {
  // 入力
  vector<vector<int>> data;
  for (int i = 0; i < 3; i++) {
    vector<int> row(3);
    data.push_back(row);
    for (int j = 0; j < 3; j++) {
      cin >> data[i].at(j);
    }
  }
  
  // 計算
  bool flag = false;
  int a1max = *max_element(data[0].begin(), data[0].end());
  for (int i = 0; i <= a1max; i++) {
    int a1 = i;
    int b1 = data[0][0] - a1;
    int b2 = data[0][1] - a1;
    int b3 = data[0][2] - a1;
    if (b1 < 0 || b2 < 0 || b3 < 0) {
      continue;
    }
    int a2 = data[1][0] - b1;
    int a3 = data[2][0] - b1;
    if (a2 < 0 || a3 < 0) {
      continue;
    }
    if ((data[1][1] - a2) == b2 &&
        (data[1][2] - a2) == b3 &&
        (data[2][1] - a3) == b2 &&
        (data[2][2] - a3) == b3) {
      flag = true;
      break;
    }
  }
  
  // 出力
  yes_or_no(flag);
}