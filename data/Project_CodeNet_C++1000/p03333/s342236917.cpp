#include<bits/stdc++.h>
using namespace std;
int n,l[100010],r[100010],i,tmp;
long long ans;
int main(){
	scanf("%d",&n);
	for(i=0;i<n;++i)scanf("%d%d",l+i,r+i);
	sort(l,l+n+1);sort(r,r+n+1);
	for(i=0;i<n;++i){if((tmp=l[n-i]-r[i])<1)break;ans+=tmp;}
	return !printf("%lld\n",ans<<1);
}