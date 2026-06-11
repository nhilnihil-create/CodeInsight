#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int n;
int a[N], b[N];
int Count(int l,int r){
	return upper_bound(b+1,b+n+1,r) - upper_bound(b+1,b+n+1,l-1);
}
int main(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) cin >> b[i];
	int ans = 0;
	for(int k=28;k>=0;k--){
		int T = 1<<k;
		for(int i=1;i<=n;i++) a[i] %= (T<<1), b[i] %= (T<<1);
		sort(b+1,b+n+1);
		int cnt = 0;
		for(int i=1;i<=n;i++){
			cnt += Count(T - a[i], (T<<1) - a[i] - 1);
			cnt += Count(T + (T<<1) - a[i], (T<<2) - a[i] - 1);
		}
		if(cnt%2) ans += T;
	}
	cout << ans;
}