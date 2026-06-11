#include<stdio.h>
using namespace std;
int main(){
  int a,b;
  scanf("%d%d",&a,&b);
  if(a*b%2==1) puts("Yes");
  else puts("No");
}