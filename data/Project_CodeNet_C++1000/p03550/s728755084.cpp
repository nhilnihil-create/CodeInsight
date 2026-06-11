#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main(void){
  int n,z,w;
  scanf("%d %d %d",&n,&z,&w);
  int a[n];
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
  }
  int ans=0;
  if(n==1){
    ans=abs(a[n-1]-w);
  }else{
    ans=max(abs(a[n-1]-w),abs(a[n-2]-a[n-1]));
  }
  printf("%d\n",ans);
  return 0;
}