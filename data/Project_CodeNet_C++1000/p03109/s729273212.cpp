#include<iostream>
#include <algorithm>
#include<string>
#include <numeric>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string sa;
  cin >>sa;
  int a,b,c;
  for(int i=0;i<sa.size();i++)
  {
      if(sa[i]=='/')sa[i]=' ';
  }
  istringstream s(sa);
  s >> a >> b >> c;
  if(a<2019)cout<<"TBD"<<endl;
  else if(b>4)cout<<"TBD"<<endl;
  else cout<<"Heisei"<<endl;
  return 0;
}
