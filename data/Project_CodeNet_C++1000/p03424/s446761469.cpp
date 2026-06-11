#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(i=0; i<n; i++)

int main() {
  int n;
  string s;
  cin >> n;
  int i, cnt;
  rep(i, n) {
    cin >> s;
    if (s=="Y") {
      cout << "Four" << endl;
      return 0;
    }
  }
  cout << "Three" << endl;
}