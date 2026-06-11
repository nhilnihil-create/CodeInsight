#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  for (auto &v : vec)
    cin >> v;

  int cnt = 0;
  for (int i = 1; i <= 100; ++i) {
    bool flag = false;
    for (auto &h : vec) {
      if (i <= h && flag == false) {
        flag = true;
        ++cnt;
      }
      else if (h < i) {
        flag = false;
      }
    }
  }

  cout << cnt << endl;
}
