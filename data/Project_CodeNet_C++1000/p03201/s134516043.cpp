#include<bits/stdc++.h>
using namespace std;
long long n,l,r,x,ans,a[200010],s[50];
map<long long,long long>v;
int main()
{
	scanf("%lld",&n);
	for (long long i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		v[a[i]]++;
	}
	s[0]=1;
	for (int i=1;i<=32;i++)
		s[i]=s[i-1]*2; 
	sort(a+1,a+n+1);
	for (long long i=n;i>=1;i--) {
        if (v[a[i]])  {
			l=0;
			r=32;
		    while (l<r) {
			   	int mid=(l+r)/2;
			   	if (s[mid]>a[i]) r=mid;
				else l=mid+1;
		    }
		    x=s[l]-a[i];
        	if (a[i]==x&&v[x]==1) continue;
        	if (v[x]) {
	        	ans++;
	        	v[x]--;
	        	v[a[i]]--;
			}
		}
	}
	printf("%lld",ans);
}