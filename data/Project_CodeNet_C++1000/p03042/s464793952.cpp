#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;cin>>S;
  bool MM=false,YY=false;
  if(S.at(0)=='0' && S.at(1)!='0') MM=true;
  else if(S.at(0)=='1' && S.at(1)-'0'<=2) MM=true;
  if(S.at(2)=='0' && S.at(3)!='0') YY=true;
  else if(S.at(2)=='1' && S.at(3)-'0'<=2) YY=true;
  if(MM && YY) cout<<"AMBIGUOUS"<<endl;
  else if(MM) cout<<"MMYY"<<endl;
  else if(YY) cout<<"YYMM"<<endl;
  else cout<<"NA"<<endl;
}