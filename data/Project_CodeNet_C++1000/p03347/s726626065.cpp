#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int a[N],n;
long long ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	a[0]=-1;
	for (int i=1;i<=n;i++)
		if (a[i-1]<a[i]-1){
			puts("-1");
			return 0;
		}	
	for (int i=n;i;i--){
		if (a[i]==a[i+1]-1)continue;
		ans+=a[i];
	}	
	printf("%lld\n",ans);
}