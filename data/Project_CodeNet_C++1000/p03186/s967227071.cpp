#include<bits/stdc++.h>
using namespace std;
int main(){
  long long a, b, c;
  cin >> a >> b >> c;
  long long ans;
  if(b >= c){
    ans = b+c;
  }
  else{
    ans = 2*b;
    long long rest = c-b;
    if(a >= rest) ans += rest;
    else ans += a+1;
  }
  cout << ans << endl;
  return 0;
}