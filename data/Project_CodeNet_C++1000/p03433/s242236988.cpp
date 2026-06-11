#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a;
  cin >> n >> a;
  string ans;

  if (n % 500 <= a) ans = "Yes";
  else ans = "No";
  
  cout << ans << endl;
}