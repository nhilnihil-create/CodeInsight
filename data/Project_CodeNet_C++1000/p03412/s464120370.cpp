#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,arr1[200040],arr2[200040],ans;
int v1[200040],v2[200040];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++) scanf("%d",arr1+i);
	for(int i=0;i<n;i++) scanf("%d",arr2+i);
	for(int i=0;i<=28;i++)
	{
	    int now=0,s1=0,s2=0;
	    for(int j=0;j<n;j++) if(arr1[j]&(1<<i)) s1^=1;
	    for(int j=0;j<n;j++) if(arr2[j]&(1<<i)) s2^=1;
	    if((s1^s2)&n&1) now^=1;
		for(int j=0;j<n;j++) v1[j]=(arr1[j]&((1<<i)-1));
		for(int j=0;j<n;j++) v2[j]=(arr2[j]&((1<<i)-1));
		//sort(v1,v1+n);
		sort(v2,v2+n);
		ll cnt=0;
		for(int j=0;j<n;j++)
            cnt+=v2+n-lower_bound(v2,v2+n,(1<<i)-v1[j]);
		cnt%=2;
		if(cnt) now^=1;
		ans|=(now<<i);
	} printf("%d",ans);
}
