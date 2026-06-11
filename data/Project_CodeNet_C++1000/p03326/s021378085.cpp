#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 1005;
ll x[N][3], a[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, m;
	cin>>n>>m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			cin>>x[i][j];
		}
	}
	ll ans = 0;
	for(int mask = 0; mask < 8; mask++){
		for(int i = 0; i < n; i++){
			a[i] = 0;
			for(int j = 0; j < 3; j++){
				if(mask&(1<<j))a[i] += x[i][j];
				else a[i] -= x[i][j];
			}
		}
		sort(a, a + n, greater<ll>());
		ll sum = accumulate(a, a + m, 0LL);
		ans = max(ans, sum);
	}
	cout<<ans<<'\n';

	return 0;
}