#include <iostream>
 
using namespace std;
 
int main()
{
  int A,P,tot;;
  cin>>A>>P;
 if(A>=0&&P>=0&&A<=100&&P<=100){
  tot=((A*3)+P)/2;
  cout<<tot;
 }
    return 0;
}