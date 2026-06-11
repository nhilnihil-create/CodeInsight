#include<bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int C=1e5+10;

int a[N],b[N];

int main(){
	int n;
	scanf("%d",&n);
	a[C]++; 
	b[C]++;
	for(int i=0;i<n;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		l+=C;
		r+=C;
		a[l]++;
		b[r]++;
	}
	for(int i=N-2;i>=0;i--) a[i]+=a[i+1];
	for(int i=1;i<N;i++) b[i]+=b[i-1];
	long long ans=0;
	for(int i=0;i<N;i++) ans+=min(a[i+1],b[i]);
	printf("%lld",ans*2);
	return 0;
}