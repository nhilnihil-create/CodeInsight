#include <bits/stdc++.h>
using namespace std;
int main() {
  string s; cin>>s;
  int n=0;
  for(char c:s.substr(2,s.size()-3)) if(c=='C') n++;
  if(s[0]!='A'||s[1]<'Z'+1||n!=1){cout<<"WA"; return 0;} 
  else for(char c:s.substr(2)) if(c<'Z'+1&&c!='C'){cout<<"WA"; return 0;}
  cout<<"AC";
}