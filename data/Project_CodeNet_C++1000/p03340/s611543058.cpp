#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define M 200005
int a[M];
int main(){
	int n,now=0,l=1;ll ans=0;
	scanf("%d",&n);
	for(int r=1;r<=n;r++){
		scanf("%d",&a[r]);
		while((a[r]^now)!=a[r]+now)now^=a[l++];
		now^=a[r];
		ans+=r-l+1;
	}
	printf("%lld\n",ans);
	return 0;
}