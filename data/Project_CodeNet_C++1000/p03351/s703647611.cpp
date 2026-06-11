#include<stdio.h>
int abs(int,int);
int main(void){
  int a,b,c,d;
  scanf("%d %d %d %d",&a,&b,&c,&d);
  if(abs(a,c)<=d || (abs(a,b)<=d && abs(b,c)<=d)){
    printf("Yes");
  }else{
    printf("No");
  }
  return 0;
}
int abs(int x,int y){
  int sub=x-y;
  if(sub<=0){
    sub=-1*sub;
  }
  return sub;
}