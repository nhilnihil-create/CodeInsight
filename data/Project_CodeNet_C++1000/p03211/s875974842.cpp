#include <iostream>
#include <string>
#include <climits>

using namespace std;

int main() {
  string str;
  cin >> str;
  int ans = INT_MAX;
  for (int i = 0; i + 2 < static_cast<int>(str.size()); ++i) {
    int tmp = stoi(str.substr(i, 3));
    ans = min(ans, abs(753 - tmp));
  }
  cout << ans << endl;
}