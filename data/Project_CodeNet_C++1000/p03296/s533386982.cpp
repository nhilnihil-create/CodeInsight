#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n;
  cin >> n;
  int a[n];
  rep(i,n) cin >> a[i];
  int p = 1;
  int ans = 0;
  rep(i,n) {
    if(i >= 1 && a[i] == a[i-1]) p++;
    else {
      ans += p/2;
      p = 1;
    } 
  }
  ans += p/2;
  cout << ans << endl;
  return 0;
}