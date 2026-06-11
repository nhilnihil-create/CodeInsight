#include<bits/stdc++.h>
using namespace std;
int main(){
  long n;
  cin >> n;
  long ans = 0;
  for(int i=1;i<=sqrt(n);i++){
    if(n%i==0 && n/i-1 > i){
      ans += (n/i)-1;
    }
  }
  if(n==2)ans = 0;
  cout << ans << endl;
}
