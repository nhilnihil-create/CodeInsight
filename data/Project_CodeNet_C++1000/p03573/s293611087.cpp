#include<iostream>
#include<algorithm>
using namespace std;
int a[5],b[100000];
int main(){
  cin>>a[1]>>a[2]>>a[3];
  sort(a+1,a+1+3);
  if(a[1]==a[2])  cout<<a[3]<<endl;
  else  cout<<a[1]<<endl;
  return 0;
}