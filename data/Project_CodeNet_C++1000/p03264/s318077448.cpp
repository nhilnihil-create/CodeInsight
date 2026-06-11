#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int k;cin>>k;
  int ans = pow(k/2, 2.0);
  if (k%2 == 1) ans += k/2;
  cout << ans  << endl;
}
