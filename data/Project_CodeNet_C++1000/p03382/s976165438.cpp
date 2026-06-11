// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ll long long
#define debug(a) cout<<#a<<": ";for(auto i:a)cout<<i<<" ";cout<<endl;
#define trace(a) cout<<#a<<": "<<a<<endl;
int a[N];
int main() {
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	int i,j,k,l,m,n,t;
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> a[i];

	}
	sort(a+1,a+n+1);
	int it = lower_bound(a+1,a+n+1,a[n]/2) - a;
	if(it == n) {
		it--;
	}
	m = a[n];
	int r1 = a[it];
	int r2 = a[it-1];
	// cout << r1 << " " << r2 << endl;
	int r = it;
	if(abs(r1 - (m-r1)) > abs(r2 - (m-r2))) {
		r = it-1;
	}
	cout << a[n] << " " << a[r] << endl;

}