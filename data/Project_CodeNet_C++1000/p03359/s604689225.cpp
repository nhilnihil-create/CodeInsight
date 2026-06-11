#include<iostream>
using namespace std;
int main(){
  int a,b;
  int res=0;
  cin>>a>>b;
  res=a-1;
  if(a<=b)res++;
  cout<<res<<endl;
  return 0;
}