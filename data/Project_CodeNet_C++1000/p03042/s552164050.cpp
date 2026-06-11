#include<iostream>
using namespace std;

int main(){
  char a,b,c,d;
  cin>>a>>b>>c>>d;
  if((a=='0' && b>='1' && b<='9')||(a=='1' && b>='0' && b<='2')){
    if((c=='0' && d>='1' && d<='9')||(c=='1' && d>='0' &&d<='2'))
    cout<<"AMBIGUOUS";
    else
    cout<<"MMYY";
  }
  else if((c=='0' && d>='1' && d<='9')||(c=='1' && d>='0' &&d<='2'))
  cout<<"YYMM";
  else
  cout<<"NA";
  return 0;
}