#include <bits/stdc++.h>
using namespace std;
 
int main(){
  long long a,b,c;
  cin >> a >> b >> c;
  long long ans = 0;
  if(c >= a + b + 1){
    ans += a + b + 1 + b;
  }else{
    ans += b + c;
  }
  cout << ans << endl;
}