#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  string s,t;
  cin >> s >> t;
  reverse(s.begin(), s.end());
  string ans;
  if(s==t) ans = "YES";
  else ans = "NO";
  cout << ans << endl;
  return 0;
}
