#include <bits/stdc++.h>
using namespace std;

int n, a[200004];
long long sum[200004];

long long rangeSum(int s, int e){
	return sum[e]-sum[s-1];
}
long long calGap(int lo, int mid, int hi){
	return	(max(max(rangeSum(1,lo),rangeSum(lo+1,mid)),max(rangeSum(mid+1,hi),rangeSum(hi+1,n)))-
	min(min(rangeSum(1,lo),rangeSum(lo+1,mid)),min(rangeSum(mid+1,hi),rangeSum(hi+1,n))));
}

int main() {
	cin>>n;
	sum[0] = 0;
	for(int i = 1 ; i <= n ; i++){
		cin>>a[i];
		sum[i] = sum[i-1]+a[i];
	}
	int mid, lo, hi;
	long long ans = 1e16;
	for(mid = 2;mid<=n-2;mid++){
		long long l = sum[mid]/2;
		lo = lower_bound(sum+1,sum+mid+1,l)-sum;
		long long h = (sum[n]+sum[mid])/2;
		hi = lower_bound(sum+mid+2,sum+n+1,h)-sum;
		ans = min(ans,calGap(lo,mid,hi));
		if(lo>1 && hi>mid+1)
			ans = min(ans,calGap(lo-1,mid,hi-1));
		if(lo>1)
			ans = min(ans,calGap(lo-1,mid,hi));
		if(hi>mid+1)
			ans = min(ans,calGap(lo,mid,hi-1));
	}
	cout<<ans;
	return 0;
}