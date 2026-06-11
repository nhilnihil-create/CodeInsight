#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b;
  string ans;
  cin >> a >> b;
  if(a%2==1 && b%2 == 1){
    ans = "Odd";
  }else{
    ans = "Even";
  }
  cout << ans << endl;
}