#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=200005;
long long sum,a[N],n,l=1,r=1,tmp=0;
int main() {
	scanf("%lld",&n);
	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
	while(r<=n) {
		while( ( (a[r]^tmp) == (a[r]+tmp) )&& r<=n) tmp^=a[r],r++;
		if(r!=n+1) sum+=r-l;
		else sum+=(r-l)*(r-l+1)/2;
		tmp^=a[l++];
	}
	printf("%lld\n",sum);
}