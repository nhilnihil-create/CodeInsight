#include<bits/stdc++.h>
#define N 500005
using namespace std;
int a[N],n,max1,kk;
int main(){
	scanf("%d",&n);int min1=1e9;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),max1=max(max1,a[i]);
	for (int i=1;i<=n;i++){
		if (a[i]==max1) continue;
		if (abs(a[i]-(max1/2))<min1){
			min1=abs(a[i]-(max1/2));
			kk=a[i];
		}
	}
	printf("%d %d\n",max1,kk);
	return 0;
}