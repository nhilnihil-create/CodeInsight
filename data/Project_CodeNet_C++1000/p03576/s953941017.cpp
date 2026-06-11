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
	vector<int> x(n), y(n), vx(n), vy(n);
	for(int i = 0; i < n; i++){
		cin>>x[i]>>y[i];
		vx[i] = x[i];
		vy[i] = y[i];
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	ll ans = LLONG_MAX;
	for(int il = 0; il + 1 < n; il++){
		for(int ir = il + 1; ir < n; ir++){
			for(int jl = 0; jl + 1 < n; jl++){
				for(int jr = jl + 1; jr < n; jr++){
					int cnt = 0;
					for(int i = 0; i < n; i++){
						if(vx[il] <= x[i] && x[i] <= vx[ir] && vy[jl] <= y[i] && y[i] <= vy[jr])cnt++;
					}
					if(cnt >= k)ans = min(ans, (vx[ir] - vx[il])*1LL*(vy[jr] - vy[jl]));
				}
			}
		}
	}
	cout<<ans<<'\n';

	return 0;
}