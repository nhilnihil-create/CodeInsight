#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  sort(a.rbegin(), a.rend());
  int alice = 0;
  int bob = 0;
  rep(i,n){
    if(i%2 == 0) alice += a[i];
    if(i%2 == 1) bob += a[i];
  }
  int ans;
  ans = alice - bob;
  cout << ans << endl;
}