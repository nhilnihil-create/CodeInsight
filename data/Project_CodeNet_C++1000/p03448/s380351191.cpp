#include<iostream>
using namespace std;
int main(){

  int A,B,C,X;
  cin>>A>>B>>C>>X;
  int count=0;
  for(int x=0;x<=A;x++){
    
    for(int y=0;y<=B;y++){
    
      if((X-(500*x)-(100*y))>=0&&(X-(500*x)-(100*y))%50==0){
      
        if((X-(500*x)-(100*y))/50<=C){
          count++;
        }
      }
    }
  }
  cout<<count;
}