#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],c[N],n,d[N],b[N],Ans;
int count(int x){
	int l=0,r=n;
	while (l<r){
		int mid=(l+r+1)/2;
		if (d[mid]>x)r=mid-1;
		else l=mid;
	}
	return l;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)scanf("%d",&b[i]);
	for (int i=0;i<29;i++){
		int T=1<<i,ans=0;
		for (int j=1;j<=n;j++)c[j]=a[j]%(2*T);
		for (int j=1;j<=n;j++)d[j]=b[j]%(2*T);
		sort(d+1,d+n+1);
		for (int j=1;j<=n;j++)
			(ans+=count(T*2-1-c[j])+count(T*4-1-c[j])-count(T*3-1-c[j])-count(T-1-c[j]))%=2;
		if ((ans+2)%2)Ans+=T;
	}
	printf("%d\n",Ans);
}