#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  int n,ans; cin >>n >>ans;
  rep(i,n-1) {
    int a; cin >>a;
    ans = gcd(a,ans);
  }
  cout << ans << endl;
  return 0;
}