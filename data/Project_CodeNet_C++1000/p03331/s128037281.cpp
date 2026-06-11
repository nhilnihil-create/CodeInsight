#include <bits/stdc++.h>
using namespace std;
int main(void){
  int N;
  cin>>N;
  int b,min=1<<30;
  for(int a=1;a<N;a++){
    int t=a,u=N-a,suma=0,sumb=0;
    while(t!=0||u!=0){
      suma+=t%10;
      t/=10;
      sumb+=u%10;
      u/=10;
    }
    
    if(min>suma+sumb){
      min=suma+sumb;
    }


  }
  printf("%d",min);
}