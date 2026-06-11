#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n, k;
  cin >> n >> k;
  
  long long cnt = n / k;
  long long cnts = (n + k / 2) / k;
  
  long long ans = pow(cnt, 3);
  if(k%2 == 0) ans += pow(cnts, 3);
  cout << ans << endl;
}