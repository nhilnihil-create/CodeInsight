#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  if(s.length() == 2) cout << s << endl;
  else{
    for(int i = 2; i >= 0; i--) cout << s[i];
    cout << endl;
  }  
  return 0;
}