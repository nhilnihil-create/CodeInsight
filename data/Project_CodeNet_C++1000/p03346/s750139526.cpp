#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
typedef long long LL;

int n, a[N], ans = 1e9 + 8, f[N];

int main() {
	cin>>n;
	for(int i = 1; i <= n; i++) {
		cin>>a[i];
		f[a[i]] = 1 + f[a[i] - 1];
		ans = min(ans, n - f[a[i]]);
	}
	cout<<ans<<endl;
	return 0;
}