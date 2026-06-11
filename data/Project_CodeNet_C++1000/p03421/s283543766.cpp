#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,A,B,a[N],b[N];
int main(){
	scanf("%d%d%d",&n,&A,&B);
	int kk=n;
	a[1]=A;n-=A;
	for (int i=2;i<=B;i++){
		a[i]=n/(B-i+1);
		n-=n/(B-i+1);
	}
	if (n){
		puts("-1");
		return 0;
	}
	for (int i=2;i<=B;i++)
		if (!a[i]||a[i]>A){
			puts("-1");
			return 0;
		}
	n=kk;	
	for (int i=1,j=1,now=n;i<=B;i++){
		for (int k=a[i];k;k--)b[j++]=now-k+1;
		now-=a[i];
	}
	for (int i=1;i<=n;i++)printf("%d ",b[i]);
	return 0;	
}