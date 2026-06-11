#include<stdio.h>
#include<algorithm>
#include<utility>
using namespace std;
int a,b,c;
int main(){
  scanf("%d%d%d",&a,&b,&c);
  if(a>b){
    swap(a,b);
  }
  if(a<c && c<b){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  
}