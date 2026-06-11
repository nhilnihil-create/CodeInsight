#include<bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int a,b;
  a=(s.at(0)-48)*10+s.at(1)-48;
  b=(s.at(2)-48)*10+s.at(3)-48;
  if(a<13&&a>0&&b<13&&b>0)
    cout << "AMBIGUOUS";
  else if(a<13&&a>0)
    cout << "MMYY";
  else if(b<13&&b>0)
    cout << "YYMM";
  else
    cout << "NA";
  cout << endl;
  return 0;
}