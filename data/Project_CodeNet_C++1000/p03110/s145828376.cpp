#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  double ans=0,t;
  string s;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> t >> s;
    if(s == "JPY") {
      ans += t;
    } else {
      ans += t*380000.0;
    }
  }
  cout << ans << endl;
}