#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int N=300005;

int n,a[N];

int main() {
	
	scanf("%d",&n);
	for (int i=0;i<n;++i) scanf("%d",&a[i]);
	
	//tow-pointers;
	
	int l=0,r=-1;
	
	long long tot1=0,tot2=0,ans=0;
	
	while(l<n) {
		while(r<n && tot1==tot2) {
			++r;
			tot1+=a[r];
			tot2^=a[r];
		}
		ans+=(long long)(r-l);
		tot1-=a[l];
		tot2^=a[l];
		++l;
	}
	printf("%lld\n",ans);
	
	return 0;
}