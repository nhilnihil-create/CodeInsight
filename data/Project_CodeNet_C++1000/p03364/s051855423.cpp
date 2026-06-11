#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<string> S;

  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;

    S.push_back(s);
  }

  int ans = 0;

  int a = 0;
  for (int b = 0; b < N; ++b) {
    bool sym = true;

    for (int y = 0; y < N - 1 && sym; ++y) {
      for (int x = y + 1; x < N && sym; ++x) {
        int y1 = (y + a) % N;
        int x1 = (x + b) % N;
        int y2 = (x + a) % N;
        int x2 = (y + b) % N;

        if (S[y1][x1] != S[y2][x2]) {
          sym = false;
        }
      }
    }

    if (sym) {
      ans += N;
    }
  }

  cout << ans << endl;

  return 0;
}
