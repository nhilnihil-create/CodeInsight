#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int y=1000*(int)(s.at(0)-'0')+100*(int)(s.at(1)-'0')+10*(int)(s.at(2)-'0')+(int)(s.at(3)-'0');
  int m=10*(int)(s.at(5)-'0')+(int)(s.at(6)-'0');
  int d=10*(int)(s.at(8)-'0')+(int)(s.at(9)-'0');
  cout<<(y<=2019&&(y<2019||m<=4)&&(m<4||d<=30)?"Heisei":"TBD")<<endl;
}