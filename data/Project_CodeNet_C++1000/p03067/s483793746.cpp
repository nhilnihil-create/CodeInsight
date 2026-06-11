#include<stdio.h>
#include<algorithm>
#include<utility>
using namespace std;
  
int main(){
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  printf("%s",(min(a,b)<c && c<max(b,a)) ? "Yes" : "No" );
  return 0; 
}