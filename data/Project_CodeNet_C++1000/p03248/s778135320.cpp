#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();

  // 構築できない場合
  if (s[0] == '0' || s[n-1] == '1') {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n/2; ++i) {
    if (s[i] != s[n-i-2]) {
      cout << -1 << endl;
      return 0;
    }
  }
  int half = n/2;
  cout << "1 2" << endl;
  int from = 2;
  for (int to = 1; to < half; ++to) {
    cout << from << " " << to+2 << endl;
    if (s[to] == '1') {
      from = to+2;
    }
  }
  for (int to = half+1; to < n; ++to) {
    cout << from << " " << to+1 << endl;
  }
}
