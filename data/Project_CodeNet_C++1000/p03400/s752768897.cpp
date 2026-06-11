#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,d,x;
  cin >> n >> d >> x;
  int ans=x,t;
  for (int i=0; i<n; i++) {
    cin >> t;
    ans += (d-1)/t+1;
  }
  cout << ans << endl;
}