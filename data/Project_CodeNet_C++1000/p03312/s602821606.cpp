#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5+1;
int n, a[N], pre[N], f1[N], f2[N];

int sum(int l,int r){
	return pre[r] - pre[l-1];
}

signed main(){
	cin >> n;
	for(int i=1;i<=n;++i) cin >> a[i], pre[i] = pre[i-1] + a[i];
	
	f1[2] = 1;
	for(int i=3,l=1;i<=n-2;++i){
		while(abs(sum(l+1,i)-sum(1,l))>abs(sum(l+2,i)-sum(1,l+1))) ++l;
		f1[i] = l;
	}
	f2[n-1] = n;
	for(int i=n-2,r=n;i>=3;--i){
		while(i<=r-2 && abs(sum(i,r-1)-sum(r,n))>abs(sum(i,r-2)-sum(r-1,n))) --r;
		f2[i] = r;
	}	
	int ans = 1e18;
	for(int i=2;i<=n-2;++i){
		int l1 = sum(1,f1[i]), l2 = sum(f1[i]+1,i);
		int r1 = sum(i+1,f2[i+1]-1), r2 = sum(f2[i+1],n);

		ans = min(max({l1,l2,r1,r2}) - min({l1,l2,r1,r2}), ans);
	}
	cout << ans;
}