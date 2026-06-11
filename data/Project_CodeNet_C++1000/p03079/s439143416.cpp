#include<iostream>
using namespace std;
int a,b,c;
main(){
  cin>>a>>b>>c;
  cout<<(a-b|b-c?"No":"Yes")<<endl;
}