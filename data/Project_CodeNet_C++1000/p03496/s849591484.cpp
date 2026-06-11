#include<cstdio>
#include<cmath>
using namespace std;
int main(){
  int n,a[50],mina,minp,maxa,maxp;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
  maxa=mina=a[0];
  minp=maxp=0;
  for(int i=1;i<n;i++){
    if(a[i]<mina){
      mina=a[i];
      minp=i;
    }
    if(a[i]>maxa){
      maxa=a[i];
      maxp=i;
    }
  }
  printf("%d\n",2*n-1);
  for(int i=1;i<=n;i++){
    if(abs(mina)>abs(maxa))
      printf("%d %d\n",minp+1,i);
    else
      printf("%d %d\n",maxp+1,i);
  }
  if(abs(mina)>abs(maxa))
    for(int i=n;i>1;i--)
      printf("%d %d\n",i,i-1);
  else
    for(int i=1;i<n;i++)
      printf("%d %d\n",i,i+1);
}