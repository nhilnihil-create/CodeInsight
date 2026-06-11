#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int a, b; cin >> a >> b;
  string s; cin >> s;
  bool ans = true;
  for(int i = 0; i < a; i++){
    if(s[i]-'0'>=0 && s[i]-'0'<= 9) continue;
    else ans = false;
  }
  if(s[a]!='-') ans = false;
  for(int i = a+1; i < a+b+1; i++){
    if(s[i]-'0'>=0 && s[i]-'0'<= 9) continue;
    else ans = false;
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
    