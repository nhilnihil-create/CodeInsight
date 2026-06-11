#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s,t;
  cin >> s >> t;
  sort(s.begin(),s.end());
  sort(t.begin(),t.end(), greater<char>());
  string ans;
  if (s < t){
    ans = "Yes";
  }else{
    ans = "No";
  }
  cout << ans << endl;
}