#include<iostream>
using namespace std;
int max3(int x,int y,int z){
  int max=0;
  if(x>y){
    max=x;
  }else{
    max=y;
  }
  if(max<z){
    max=z;
  }
  return max;
}
int main(void){
  int a,b;
  cin>>a>>b;
  int add=a+b;
  int sub=a-b;
  int mul=a*b;
  int ans=max3(add,sub,mul);
  printf("%d\n",ans);
  return 0;
}