#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 2e5 + 5;

int n;
LL ans = 9e18, d[N], x;

int main() {
	cin>>n>>x;
	for(int i = 1; i <= n; i++) 
		cin>>d[i], d[i] += d[i - 1];
	for(int k = 1; k <= n; k++) {
		LL res = 0, j = 3;
		for(int i = n; i >= 1; i -= k) {
			res += (d[i] - d[max(0, i - k)])*max(5ll, j);
			j += 2;
			if(res >= ans) break;
		}
		ans = min(ans, res + k*x);
	}
	cout<<ans + n*x<<endl;
}