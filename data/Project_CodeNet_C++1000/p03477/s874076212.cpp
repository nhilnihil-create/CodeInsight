#include<iostream>
using namespace std;
int main(){
  int A,B,C,D,X,Y;cin>>A>>B>>C>>D;
  X=A+B; Y=C+D;
  cout << (X>Y?"Left":(X<Y?"Right":"Balanced"));
}