#include<iostream>
using namespace std ;

int main()
{
  int A,B,C,X,Y ;
  cin>>A>>B>>C>>X>>Y ;
  
  int min_money=0 ;
  if(X>Y){
    if(2*C>A+B) min_money+=Y*(A+B) ;
    else min_money+=2*C*Y ;
    if(2*C<A) min_money+=2*C*(X-Y) ;
    else min_money+=A*(X-Y) ;
  }else if(X<Y){
    if(2*C>A+B) min_money+=X*(A+B) ;
    else min_money+=2*C*X ;
    if(2*C<B) min_money+=2*C*(Y-X) ;
    else min_money+=B*(Y-X) ;
  }else{
    if(2*C>A+B) min_money+=X*(A+B) ;
    else min_money+=X*2*C ;
  }
  
  cout<<min_money<<endl ;
  
  return 0 ;
}