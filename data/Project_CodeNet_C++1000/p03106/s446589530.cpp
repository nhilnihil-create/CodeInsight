#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int a,b,k;
  cin >> a >>b >> k;
  int cnt  = 0;
  int ans;
  for(int i = 100; i >=1 ;i--){
    if(a%i ==0 && b%i == 0) cnt++;
    if(cnt == k) {
      ans = i;
    break;
  }
  }
  cout << ans << endl;
}
  
