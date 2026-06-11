#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, x;
  cin >> n >> x;
  int a[n], ans = 0;
  for(int i=0; i<n; ++i) cin >> a[i];
  sort(a, a+n);
  for(int i=0; i<n; ++i){
    if(x < a[i]) break;
    ++ans;
    x -= a[i];
  }
  if(ans == n && x) --ans;
  cout << ans << endl;
}