#include <bits/stdc++.h>
using namespace std;
int main(){
  string S;
  cin>>S;
  int a=S.at(0)-'0',b=S.at(1)-'0',c=S.at(2)-'0',d=S.at(3)-'0';
  
  if(a+b+c+d==7){
    cout<<a<<"+"<<b<<"+"<<c<<"+"<<d<<"=7"<<endl;
  }
  
  else if(a+b+c-d==7){
    cout<<a<<"+"<<b<<"+"<<c<<"-"<<d<<"=7"<<endl;
  }
  
  else if(a+b-c+d==7){
    cout<<a<<"+"<<b<<"-"<<c<<"+"<<d<<"=7"<<endl;
  }
  
  else if(a+b-c-d==7){
    cout<<a<<"+"<<b<<"-"<<c<<"-"<<d<<"=7"<<endl;
  }
  
  else if(a-b+c+d==7){
    cout<<a<<"-"<<b<<"+"<<c<<"+"<<d<<"=7"<<endl;
  }
  
  else if(a-b+c-d==7){
    cout<<a<<"-"<<b<<"+"<<c<<"-"<<d<<"=7"<<endl;
  }
  
  else if(a-b-c+d==7){
    cout<<a<<"-"<<b<<"-"<<c<<"+"<<d<<"=7"<<endl;
  }
  
  else if(a-b-c-d==7){
    cout<<a<<"-"<<b<<"-"<<c<<"-"<<d<<"=7"<<endl;
  }
}  