#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<vector<int>> vec(3, vector<int>(3));
  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j)
      cin >> vec[i][j];

  bool flag = false;
  for (int a1 = 0; a1 <= 100; ++a1) {
    int b1 = vec[0][0] - a1;
    int b2 = vec[0][1] - a1;
    int b3 = vec[0][2] - a1;
    int a2 = vec[1][0] - b1;
    int a3 = vec[2][0] - b1;
    vector<int> as = {a1, a2, a3};
    vector<int> bs = {b1, b2, b3};
    bool flag2 = true;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (vec[i][j] != as[i] + bs[j])
          flag2 = false;
      }
    }
    if (flag2)
      flag = true;
  }
  cout << (flag ? "Yes" : "No") << endl;

}
