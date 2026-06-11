#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  ll n;
  cin >>n;
  bool nine = true;
  int cnt = 0;
  while(n>=10){
    if(n%10!=9) nine = false;
    n /= 10;
    cnt++;
  }
  int ans = n+9*cnt;
  if(nine) cout << ans << endl;
  else cout << ans-1 << endl;
  return 0;
}
