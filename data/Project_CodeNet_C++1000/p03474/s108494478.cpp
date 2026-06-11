#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int a, b;
  cin >> a >> b;
  string s, ans="Yes";
  cin >> s;
  for(int i=0; i<a; i++){
    if(s[i]=='-') ans = "No";
  }
  if(s[a]!='-') ans = "No";
  for(int i=a+1; i<a+b+1; i++){
    if(s[i]=='-') ans = "No";
  }
  cout << ans << endl;
  return 0;
}
