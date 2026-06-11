#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b;
  string s;
  string ans = "Yes";
  cin >> a >> b >> s;
  
  if (s[a] != '-'){
    ans = "No";
  }
  for (int i=0;i<a+b+1;i++){
    if (s[i] == '-' && i != a){
      ans = "No";
    }
  }
  cout << ans << endl;
}