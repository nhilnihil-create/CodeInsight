#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >>s;
  int sa=INT_MAX;
  for(int i=0;i<s.size()-2;i++){
    int a,b,c;
    a=(s[i+0]-'0')*100;
    b=(s[i+1]-'0')*10;
    c=s[i+2]-'0';
    sa=min(abs(a+b+c-753),sa);
    //cout<<a+b+c<<endl;
  }
  cout<<sa<<endl;
  return 0;
}