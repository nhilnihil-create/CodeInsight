#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  long long n;
  cin >> s >> n;
  bool flag = true;
  char ans;
  for(int i = 0; i < n; i++){
    if(s[i] != '1') {flag = false; ans = s[i]; break;}
  }
  if(flag) cout << 1 << endl;
  else cout << ans << endl;
}