#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll N, K;
	cin >> N >> K;

	vector <ll> x(N);
	vector <ll> y(N);
	for (int ii = 0; ii < N; ++ii){
		cin >> x[ii] >> y[ii];
	}

	ll ans = -1;
	for (int ii = 0; ii < N-1; ++ii){
		for (int jj = ii+1; jj < N; ++jj){
			for (int kk = 0; kk < N-1; ++kk){
				for (int nn = kk+1; nn < N; ++nn){
					ll x1 = x[ii];
					ll x2 = x[jj];
					ll y1 = y[kk];
					ll y2 = y[nn];
					ll minX = min(x1, x2);
					ll maxX = max(x1, x2);
					ll minY = min(y1, y2);
					ll maxY = max(y1, y2);

					//範囲内の点数を数える
					ll cnt = 0;
					for (int mm = 0; mm < N; ++mm){
						if ( x[mm]<minX || x[mm]>maxX || y[mm]<minY || y[mm]>maxY ){
						} else {
							cnt++;
						}
						if (cnt >= K){
							if (ans == -1){
								ans = (maxX-minX)*(maxY-minY);
							} else {
								ans = min(ans, (maxX-minX)*(maxY-minY));	
							}
							break;
						}
					}
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}
