#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;
  
  long long ans = 0;
  for(int i = 1; i < n; i++){
    long long now = (n-i) / i;
    if(now <= i) break;
    if((n-i) % i) continue;
    ans += now;
  }
  
  cout << ans << endl;
}