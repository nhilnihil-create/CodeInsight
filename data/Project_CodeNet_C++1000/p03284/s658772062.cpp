#include <bits/stdc++.h>
using namespace std;

int main () {
  int n,k;
  cin >> n >> k;

  int ans;
  if (n%k==0) ans=0;
  else ans=1;

  cout << ans << endl;
  return 0;
}
