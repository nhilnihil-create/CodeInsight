#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  string res = "No";
  if((s[0] == s[1] && s[1] == s[2]) || (s[1] == s[2] && s[2] == s[3])){
    res = "Yes";
  }
  cout << res;
}