#include<bits/stdc++.h>
using namespace std;
int main(){
int a[10009],n,i;
scanf("%d\n",&n);
long long sum=0;
for(i=1;i<=n;i++){
	scanf("%d",&a[i]);
	sum+=a[i]-1;
}
printf("%lld\n",sum);
	return 0;
}