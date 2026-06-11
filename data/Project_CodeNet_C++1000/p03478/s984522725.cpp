#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  
  string s;
  int sum = 0;
  int ans = 0;
  for(int i=1; i<=n; i++) {
    s = to_string(i);
    for(int j=0; j<s.size(); j++) {
      sum += s[j]-'0';
      if(j==s.size()-1 && a<=sum && sum<=b) ans += i;
    }
    sum = 0;
  }
  cout << ans << endl;
  return 0;
}