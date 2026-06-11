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
  int ans = 0;
  vector<int> cosin(5);
  for (int i = 0; i < 5; i++) {
    cin >> cosin[i];
  }
  int Min = 999999;
  do {
    ans = 0;
    for (int i = 0; i < 4; i++) {
      ans += cosin[i];
      if (ans % 10 != 0) {
        ans += (10 - ans % 10);
      }
    }
    ans += cosin[4];
    Min = min(Min, ans);
  } while (next_permutation(cosin.begin(), cosin.end()));
  cout << Min << endl;
}
