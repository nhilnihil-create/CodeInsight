#include<stdio.h>
#include<algorithm>
using namespace std;
int a,b,c;
int main(){
  scanf("%d%d%d",&a,&b,&c);
  if(min(a,b)<c && c<max(a,b)){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  
}