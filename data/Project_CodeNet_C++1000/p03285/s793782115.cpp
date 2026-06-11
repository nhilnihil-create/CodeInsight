#include <bits/stdc++.h>
using namespace std;

using pp=pair<int,int>;

int main() {
  int N;
  cin >> N;
  string ans="No";
  for (int i=0; i<=N/4; i++) {
    for (int j=0; j<=N/7; j++) {
      if (N==i*4+j*7) {
        ans = "Yes";
        break;
      }
    }
  }
  cout << ans << endl;
}