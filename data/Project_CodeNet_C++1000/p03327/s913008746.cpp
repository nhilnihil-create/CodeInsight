#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  string ans;
  if(1<=n && n<=999){
    ans="ABC";
  }else{
    ans="ABD";
  }
  cout << ans <<endl;
  return 0;
}