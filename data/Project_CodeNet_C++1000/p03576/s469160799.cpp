#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

ll const INF = 9223372036854775807;

int main(){
	int n,k;
	cin >> n >> k;
	vector<pair<ll,ll>> p(n);
	vector<ll> x(n);
	vector<ll> y(n);
	rep(i,n){
		ll a,b;
		cin >> a >> b;
		x[i] = a;
		y[i] = b;
		p[i] = make_pair(a,b);
	}
	ll ans = INF;
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	for (int x1 = 0; x1 < n; ++x1) {
		for (int x2 = x1+1; x2 < n; ++x2) {
			for (int y1 = 0; y1 < n; ++y1) {
				for (int y2 = y1+1; y2 < n; ++y2) {
					ll lx = x[x1];
					ll rx = x[x2];
					ll by = y[y1];
					ll uy = y[y2];
					int count = 0;
					rep(i,n){
						ll px = p[i].first;
						ll py = p[i].second;
						if(lx <= px && px <= rx && by <= py && py <= uy) count++;
					}
					if(count >= k){
						ans = min(ans, (rx-lx)*(uy-by));
					}
				}
			}
		}
	}
	cout << ans << endl;
    return 0;
}