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

	int n; cin>>n;
	int f[n][10];
	ll p[n][11];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 10; j++){
			cin>>f[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= 10; j++){
			cin>>p[i][j];
		}
	}
	ll ans = LLONG_MIN;
	for(int mask = 1; mask < (1<<10); mask++){
		ll sum = 0;
		for(int i = 0; i < n; i++){
			int cnt = 0;
			for(int j = 0; j < 10; j++){
				if(!f[i][j])continue;
				if(mask&(1<<j))cnt++;
			}
			sum += p[i][cnt];
		}
		ans = max(ans, sum);
	}
	cout<<ans<<endl;

	return 0;
}