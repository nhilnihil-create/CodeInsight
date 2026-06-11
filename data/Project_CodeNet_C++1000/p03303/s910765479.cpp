#include <bits/stdc++.h>

using namespace std;

int main(){
 string s;
  cin >> s;
  int n;
  cin >> n;
  
  
 string t="";
  
  for(int i=0;i<s.length();i+=n){
   t+=s[i];
  }
  
  
  cout << t << endl;
}
