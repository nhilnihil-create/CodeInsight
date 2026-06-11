#include <bits/stdc++.h>
using namespace std;

int main(){
int N,T,A,X;
  scanf("%d%d%d",&N,&T,&A);
    
    int c= 1000000;
  int res,d;
    for(int i=1;i<=N;i++){
    scanf("%d",&X);
      d=T*1000-6*X-1000*A;
      if(d<0)d=-d;
      if(c>d)c=d,res=i;
    }
  printf("%d\n",res);
}