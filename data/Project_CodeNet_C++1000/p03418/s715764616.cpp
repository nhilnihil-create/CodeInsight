#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, k;
	cin>>n>>k;
	if(k == 0){
		cout<<n*1LL*n<<'\n';
		exit(0);
	}
	ll ans = 0;
	for(int b = k + 1; b <= n; b++){
		for(int i = 0; i <= n; i += b){
			int l = i + k;
			int r = min(n, i + b - 1);
			if(l <= r)ans += r - l + 1;
		}
	}
	cout<<ans<<'\n';

	return 0;
}