#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <utility>
#include <cstdio>
#include <cstring>
#include <numeric>
#include <climits>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n, m) for (int i = n; i >= m; i--)

#define INF (1<<29)


int main(){
	ll N, K;
	ll x[50], y[50];

	vector<int> xar(N), yar(N);
	cin >> N >>K;
	rep(i, N){
		cin >> x[i] >> y[i];
		xar.push_back(x[i]);
		yar.push_back(y[i]);
	}
	sort(xar.begin(), xar.end());
	sort(yar.begin(), yar.end());

	ll max_area = LONG_MAX;
	rep(xi, N) {
		rep(xj, N){
			rep(yi, N){
				rep(yj, N){
					int num = 0;
					ll lx = xar[xi], rx = xar[xj];
					ll by = yar[yi], uy = yar[yj];

					rep(i, N){
						if(lx <= x[i] && x[i] <= rx && by <= y[i] && y[i] <= uy){
							num++;
						}
					}

					if(num >= K && max_area> (1ll*(rx-lx)*(uy-by))){
						max_area = 1ll * (rx-lx) * (uy-by);
					}
				}
			}
		}
	}

	cout << max_area << endl;

	return 0;
}
