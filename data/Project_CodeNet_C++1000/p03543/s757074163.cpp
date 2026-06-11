#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,d,N;
  cin >>N;
  a=N%10;
  b=N%100 - a;
  c=N%1000 -(a+b);
  d=N-(a+b+c);
  b=b/10;
  c=c/100;
  d=d/1000;
  
  if(d==c&&c==b){
    cout <<"Yes"<<endl;
  }
  
  else if(c==b&&b==a){
    cout <<"Yes"<<endl;
  }
  
  else{
    cout <<"No"<<endl;
  }
}