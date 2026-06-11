#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  int a[n], b[n];
  int as = 0, bs =0, ans = 0;
  for(int i=0; i<n; ++i) cin >> a[i];
  for(int i=0; i<n; ++i){ cin >> b[i]; bs += b[i]; }
  for(int i=0; i<n; ++i){
    as += a[i];
    if(i != 0) bs -= b[i-1];
    ans = max(ans, as+bs);
  }
  cout << ans << endl;
}