#include<iostream>
#include<algorithm>
using namespace std;
int main(){
int a,b;cin>>a>>b;
  int sum=a+b;
  int sub=a-b;
  int mul=a*b;
  int res=max(sum,sub);
  res=max(res,mul);
  cout<<res<<endl;
  return 0;
}