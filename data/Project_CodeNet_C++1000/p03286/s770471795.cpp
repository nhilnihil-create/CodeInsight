#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;

  if(n==0){
    cout << 0 << endl;
    return 0;
  }

  string ans = "";
  while(n!=0){
    if(n%2==0) ans = "0"+ans;
    else{
      ans = "1"+ans;
      n-=1;
    }
    n/=-2;
  }
  cout << ans << endl;
}