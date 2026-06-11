#include<iostream>
using namespace std;
int main(){
  int x;
  int a;
  int min=1000000000;
  int max=0;
  cin>>x;
  for(int i=0;i<x;i++){
    cin>>a;
    if(a<min)
      min=a;
    if(a>max)
      max=a;
  }
  cout<<max-min<<endl;
}