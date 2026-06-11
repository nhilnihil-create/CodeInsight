#include<iostream>
using namespace std;
int main()
{
  int a,b;
  cin>>a>>b;
  if(a%2==0&&b%2==0){
  cout<<a/2+b/2;
  }else{
    cout<<a/2+b/2+1<<endl;
  }
}
  