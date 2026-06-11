#include<stdio.h>
int main(){
int n,a[111],min=1111111,ans,i,ave,d;
scanf("%d",&n);
ave=0;
for(i=0;i<n;i++){
scanf("%d",&a[i]);
ave+=a[i];
}
for(i=0;i<n;i++){
d=a[i]*n-ave;
if(d<0)
d=-d;
if(d<min){
ans=i;
min=d;
}
}
printf("%d\n",ans);
return 0;
}