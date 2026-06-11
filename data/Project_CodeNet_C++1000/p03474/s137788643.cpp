#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin >> a >> b;
  string s;
  cin >> s;
  bool flg=true;
  for(int i=0; i<a+b+1; i++){
    if(i==a&&s[i]!='-') flg=false;
    if(i!=a&&s[i]=='-') flg=false;
  }    
  if(flg) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
