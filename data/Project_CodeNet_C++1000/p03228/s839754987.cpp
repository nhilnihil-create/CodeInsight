#include<iostream>
using namespace std ;

int main()
{
  int A,B,K ;
  cin>>A>>B>>K ;
  /*高橋君:A枚、青木君B枚*/
  for(int i=0;i<K;i++){
    if(i%2==0){
      if(A%2!=0){
        A-- ;
        B+=(A/2) ;
        A/=2 ;
      }else{
        B+=(A/2) ;
        A/=2 ;
      }
    }else{
      if(B%2!=0){
        B-- ;
        A+=(B/2) ;
        B/=2 ;
      }else{
        A+=(B/2) ;
        B/=2 ;
      }
    }
  }
  cout<<A<<" "<<B<<endl ;
  
  return 0 ;
}