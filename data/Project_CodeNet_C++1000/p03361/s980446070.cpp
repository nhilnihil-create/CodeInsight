#include <iostream>
#include <vector>

using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<string> s(H);
  for (int i = 0; i < H; i++) {
    cin >> s[i];
  }

  for (int i = 0; i != H; ++i) {
    for (int j = 0; j != W; ++j) {
      if (s[i][j] == '.') continue;
      if ((!i || s[i - 1][j] == '.') && (i + 1 == H || s[i + 1][j] == '.') &&
          (!j || s[i][j - 1] == '.') && (j + 1 == W || s[i][j + 1] == '.')) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;
}
