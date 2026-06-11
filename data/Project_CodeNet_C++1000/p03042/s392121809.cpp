#include <iostream>
using namespace std;

int main(void){
  int a;
  cin>>a;
  int front,rear;
  front=a/100;
  rear=a%100;
  
  
  if((front==0 || 12<front) && (1<=rear && rear<=12))cout<<"YYMM"<<endl;
  else if((1<=front && front<=12) && (rear==0 || 12<rear))cout<<"MMYY"<<endl;
  else if((1<=front && front<=12) && (1<=rear && rear<=12))cout<<"AMBIGUOUS"<<endl;
  else cout<<"NA"<<endl;
  
  return 0;
}
