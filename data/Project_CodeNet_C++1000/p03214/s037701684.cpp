#include<bits/stdc++.h>
int n,a[105],i,s,mn=1<<30,id;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i),s+=a[i];
	for(i=1;i<=n;++i)if(abs(a[i]*n-s)<mn)mn=abs(a[i]*n-s),id=i;
	printf("%d\n",id-1);
	return 0;
}