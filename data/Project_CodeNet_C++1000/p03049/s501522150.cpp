#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;  cin >> n;
  int _a = 0, b_ = 0, b_a = 0;
  int ans = 0;
  for(int i=0; i<n; i++){
    string s;  cin >> s;
    for(int j=1; j<s.size(); j++)
      if(s[j-1]=='A' && s[j]=='B')  ans++;
    if(s[0]=='B' && s[s.size()-1]=='A')  b_a++;
    else if(s[0]=='B')  b_++;
    else if(s[s.size()-1]=='A')  _a++;
  }

  ans += min(_a, b_);
  if(b_ || _a)  ans += b_a;
  else  ans += max(0, b_a-1);

  cout << ans << endl;
  
  return 0;
}
