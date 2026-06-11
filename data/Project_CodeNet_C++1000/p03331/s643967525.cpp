#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  if(n % 10 == 0) cout << 10 << endl;
  else{
    int ans = 0;
    while(n != 0){
      ans += n % 10;
      n /= 10;
    }
    cout << ans << endl;
  }
}