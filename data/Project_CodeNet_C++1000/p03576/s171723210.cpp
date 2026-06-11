#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e9+7;
#define ALL(x) (x).begin(),(x).end()

int main() {
	int N, K;
	cin >> N >> K;
	vector<ll> X(N), Y(N), xs(N), ys(N);
	for(int i=0;i<N;i++) {
		cin >> X[i] >> Y[i];
		xs[i] = X[i];
		ys[i] = Y[i];
	}
	xs.push_back(-2*INF);
	ys.push_back(-2*INF);
	sort(ALL(xs));
	sort(ALL(ys));
	xs.erase(unique(ALL(xs)), xs.end());
	ys.erase(unique(ALL(ys)), ys.end());

	vector<int> cx(N), cy(N);
	vector<vector<int>> sum(N+1, vector<int>(N+1,0));
	map<int,ll> tox, toy;
	for(int i=0;i<N;i++) {
		cx[i] = lower_bound(ALL(xs), X[i]) - xs.begin();
		cy[i] = lower_bound(ALL(ys), Y[i]) - ys.begin();
		tox[cx[i]] = X[i];
		toy[cy[i]] = Y[i];
		sum[cy[i]][cx[i]]++;
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			sum[i][j] = sum[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}
	ll ans = LLONG_MAX;
	// [yl, yr], [xl,xr]の範囲を求める
	for(int yl=1;yl<=N;yl++) {
		for(int yr=yl;yr<=N;yr++) {
			for(int xl=1;xl<=N;xl++) {
				for(int xr=xl;xr<=N;xr++) {
					int tsum = sum[yr][xr] - sum[yr][xl-1] - sum[yl-1][xr] + sum[yl-1][xl-1];
					if(tsum == K) {
						ans = min(ans, (toy[yr] - toy[yl]) * (tox[xr] - tox[xl]));
					}
				}
			}
		}
	}
	cout << ans << endl;
}