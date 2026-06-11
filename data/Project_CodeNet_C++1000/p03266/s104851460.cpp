#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int n,k;
  ll cnt1 = 0,cnt2 = 0,ans;
  cin >> n >> k;
  for(int i = 1;i <= n;i++){
    if(i%k == 0) cnt1++;
    if(i%k == k/2) cnt2++;
  }
  ans = cnt1*cnt1*cnt1;
  if(k%2 == 0) ans += cnt2*cnt2*cnt2;
  cout << ans << endl;
}