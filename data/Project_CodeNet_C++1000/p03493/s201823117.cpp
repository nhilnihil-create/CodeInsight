#include<iostream>
#include<string>
using namespace std;
int main(){
  int k=0;
  string a;
  cin>>a;
  if(a[0]=='1') k++;
  if(a[1]=='1') k++;
  if(a[2]=='1') k++;
  
  cout<<k<<endl;
  return 0;
}
