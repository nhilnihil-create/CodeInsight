#include<iostream>
using namespace std;
int main(){
  string a;
  cin>>a;
  int k=0;
  for(int i=0;i<3;i++){
    if(a.at(i)=='o')
      k++;
  }
  cout<<700+k*100;
  return 0;
}