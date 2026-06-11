#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  int s;
  cin >> s;
  vector<int> m(1000001);
  int cnt = 0;
  while (true) {
    cnt++;
    m[s]++;
    if (m[s] == 2) {
      cout << cnt << endl;
      return 0;
    }
    if (s % 2 == 0)
      s /= 2;
    else
      s = 3 * s + 1;
  }
}
