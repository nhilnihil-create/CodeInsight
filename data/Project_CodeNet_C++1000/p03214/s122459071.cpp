#include <iostream>
#include <algorithm>
using namespace std;
int T[105]={0};
int main(){
  int n;scanf("%d",&n);int sum=0;
  for(int i=0;i<n;i++){
    int k;scanf("%d",&k);
    sum+=k;
    T[i]=n*k;
  }
  int dif=1000000000;
  int ans=0;
  for(int i=0;i<n;i++){
    if(abs(sum-T[i])<dif){ans=i;dif=abs(sum-T[i]);}
  }
  printf("%d \n",ans);
}
