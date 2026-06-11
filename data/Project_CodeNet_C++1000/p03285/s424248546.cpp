#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string s = "No";
  for (int i = 0; i <= N / 4; i++) {
    for (int j = 0; j <= N / 7; j++) {
      int t = 4 * i + 7 * j;
      if (t == N) s = "Yes";
    }
  }
  cout << s << endl;
}
