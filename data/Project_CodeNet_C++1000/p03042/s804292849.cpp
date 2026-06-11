#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int a=(s[0]-'0')*10+(s[1]-'0');
  int b=(s[2]-'0')*10+(s[3]-'0');
  bool MMYY=1<=a&&a<=12;
  bool YYMM=1<=b&&b<=12;
  if(MMYY&&YYMM)cout<<"AMBIGUOUS"<<endl;
  else if(MMYY)cout<<"MMYY"<<endl;
  else if(YYMM)cout<<"YYMM"<<endl;
  else cout<<"NA"<<endl;
}