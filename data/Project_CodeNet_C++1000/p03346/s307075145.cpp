#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],n,x,ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		a[x]=a[x-1]+1;
		ans=max(ans,a[x]);
	}
	printf("%d\n",n-ans);
}
