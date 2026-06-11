#include<bits/stdc++.h>
using namespace std;
const int MAXN = 400005;
using lint = long long;
using pi = pair<int, int>;

int n;
lint a[MAXN];
lint ans;

void Try(int x, int y, int z){
	if(0 < x && x < y && y < z && z < n){
		lint d1 = a[x] - a[0];
		lint d2 = a[y] - a[x];
		lint d3 = a[z] - a[y];
		lint d4 = a[n] - a[z];
		ans = min(ans, max({d1, d2, d3, d4}) - min({d1, d2, d3, d4}));
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%lld",&a[i]);
		a[i] += a[i-1];
	}
	ans = 1e18;
	for(int i=2; i<=n-2; i++){
		auto l = lower_bound(a + 1, a + n + 1, (a[i] + 1) / 2) - a;
		auto r = lower_bound(a + 1, a + n + 1, a[i] + (a[n] - a[i] + 1) / 2) - a;
		for(int j = l - 3; j <= l + 3; j++){
			for(int k = r - 3; k <= r + 3; k++){
				Try(j, i, k);
			}
		}
	}
	cout << ans << endl;
}
