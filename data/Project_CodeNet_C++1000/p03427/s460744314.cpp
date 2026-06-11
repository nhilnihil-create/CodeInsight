#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;
  
  long long digit = 0, nine = 0, ans = 0;
  while(n > 9){
    long long now = n % 10;
    if(now == 9) nine++;
    digit++;
    ans += now;
    n /= 10;
  }
  
  ans += n;
  ans = max(ans, n-1+digit*9);
  
  cout << ans << endl;
}