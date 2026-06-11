#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int w = 0;
  int b = 0;

  for(int i=0;i<n;i++) {
    if(s[i] == '.') w++;
    else b++;
  }

  int ans = w;

  int now = w;

  for(int i=0;i<n;i++) {
    if(s[i] == '.') {
      now--;
      if(now < ans) ans = now;
    }
    else {
      now++;
    }
  }

  cout << ans << endl;
}