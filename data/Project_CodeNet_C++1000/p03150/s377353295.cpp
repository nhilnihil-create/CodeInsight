#include <bits/stdc++.h>
using namespace std;


int main(){
  string s;
  cin >> s;  
  
  string t="keyence";
  int n = s.size();
  
  for(int i = 0; i <t.size(); i++){
      
    string s1 = s.substr(0,i); // lay gia tri tu 0 -> 3
    string s2 = s.substr(i+n-7); // lay gia tri tu (3+n-7) den cuoi
      
    if (s1+s2 == t)
    {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
