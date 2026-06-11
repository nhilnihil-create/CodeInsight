#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
  int A,B,C,X,Y;
  cin>>A>>B>>C>>X>>Y;
  int min_price,max_price,min_number,max_number;
  max_price=2*C;
  min_price=A+B;
  if(A+B>2*C){
    max_price=A+B;
    min_price=2*C;
  }
  max_number=Y;
  min_number=X;
  if(X>Y){
  max_number=X;  
  min_number=Y;
  }
  int res=0;
  res+=min_number*min_price;
  min_number=max_number-min_number;
  if(max_number==X){
  min_price=A;
  } else{
    min_price=B;
        }
  if(min_price>2*C){
    min_price=2*C;
  }
  res+=min_number*min_price;
  cout<<res;
}
