#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  string t = "AKIHABARA";
  if(s.length() > 9){
    cout << "NO" << endl;
    return 0;
  }
  int p = 0;
  int q = 0;
  string ans = "YES";
  while(q != 9){
    if(s[p] == t[q]){
      p++;
      q++;
    }
    else if(t[q] == 'A'){
      q++;
    }
    else{
      ans = "NO";
      break;
    }
  }
  if(p != s.length()) ans = "NO";
  cout << ans << endl;
  return 0;
}