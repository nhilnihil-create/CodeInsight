#include<bits/stdc++.h>
using namespace std;

const int N = 2005;
typedef long long ll;

int n, a[N], tot, ans;
bitset <N*N> f;

int main() {
	cin>>n;
	f[0] = 1;
	for(int i = 1; i <= n; i++) {
		cin>>a[i];
		f |= f<<a[i];
		tot += a[i];
	}
	ans = (tot + 1)/2;
	while(!f[ans]) ans++;
	cout<<ans<<endl;
}