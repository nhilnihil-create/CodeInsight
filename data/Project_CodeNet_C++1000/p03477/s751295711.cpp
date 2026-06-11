#include<iostream>
using namespace std;
int main(){
  int A,B,C,D;
  cin>>A>>B>>C>>D;
  int L=A+B;
  int R=C+D;
  if(L<R){
    cout<<"Right"<<endl;
  }else if(L==R){
    cout<<"Balanced"<<endl;
  }else{
    cout<<"Left"<<endl;
  }
  return 0;
}