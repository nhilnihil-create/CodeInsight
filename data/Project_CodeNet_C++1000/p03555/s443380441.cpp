#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int cnt = 0;
  rep(i, 3) {
    if(s1.at(i) == s2.at(2-i)) {
      cnt++;
    }
  }
  if(cnt == 3) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}
