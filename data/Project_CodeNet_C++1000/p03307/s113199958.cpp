#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long n; cin>>n;
  long long ans = 0;
  if (n%2 == 0) ans = n;
  else ans = n * 2;
  cout << ans << endl;
}