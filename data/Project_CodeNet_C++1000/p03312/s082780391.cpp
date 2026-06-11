#include<bits/stdc++.h>
using namespace std;
long long n,l=1,r=3,a[4],Min,s[200010],x,y;
int main(){
	scanf("%d",&n);
	Min=2e9+5;
	for(int i=1;i<=n;i++){
		scanf("%lld",&x);
		s[i]=s[i-1]+x;
	}
	for(int i=2;i<n;i++){
		while(l<i&&abs(s[i]-s[l+1]*2)<=abs(s[i]-s[l]*2)) l++;
		while(r<n&&abs(s[n]-s[r+1]*2+s[i])<=abs(s[n]-s[r]*2+s[i]))r++;
		a[0]=s[l];
		a[1]=s[i]-s[l];
		a[2]=s[r]-s[i];
		a[3]=s[n]-s[r];
		sort(a,a+4);
		Min=min(Min,a[3]-a[0]);
	}
	printf("%d\n",Min);
	return 0;
}