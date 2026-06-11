#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  int ans=1;
  ans*=(s.at(0)=='A');
  int x=0;
  int y;
  for(int i=2;i<s.size()-1;i++){
    if(s.at(i)=='C') {x++; y=i;}
  }
  ans*=(x==1);
  for(int i=1;i<s.size();i++){
    int a=s.at(i);
    if(i!=y) ans*=(a>96);
  }
  
  if(ans) cout << "AC" << endl;
  else cout << "WA" << endl;
}