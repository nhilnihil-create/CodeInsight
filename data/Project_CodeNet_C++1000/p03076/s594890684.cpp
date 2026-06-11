#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int ans = 0;
  vector<int> amari(0);
  for (int i = 0; i < 5; i++) {
    int tmp;
    cin >> tmp;
    ans += ((tmp+9)/10)*10;
    tmp %= 10;
    amari.push_back(tmp);
  }
  sort(amari.begin(), amari.end());
  for (int i = 0; i < 5; i++) {
    if (amari[i] != 0) {
      ans -= (10-amari[i]);
      break;
    }
  }
  cout << ans << endl;
}
