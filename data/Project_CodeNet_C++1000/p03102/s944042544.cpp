#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n, m, c;
  cin >> n >> m >> c;
  vector<vector<int>> ass(n, vector<int>(m));
  vector<int> bs(m);
  for (int &b : bs) {
    cin >> b;
  }
  for (vector<int> &as : ass) {
    for (int &a : as) {
      cin >> a;
    }
  }

  int result = 0;
  for (vector<int> &as : ass) {
    int code = 0;
    for (int i = 0; i < m; i++) {
      code += as[i] * bs[i];
    }
    result += code > -c ? 1 : 0;
  }

  cout << result << endl;
  return 0;
}