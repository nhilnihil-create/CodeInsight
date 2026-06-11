#include <bits/stdc++.h>
using namespace std;
using lint = long long;
typedef pair<lint, lint> P;

signed main(){
	lint N, K; cin >> N >> K;
	vector<lint> x(N), y(N), xa, ya;
	for(int i = 0; i < N; i++) cin >> x[i] >> y[i], xa.push_back(x[i]), ya.push_back(y[i]);
	sort(xa.begin(), xa.end());
	sort(ya.begin(), ya.end());
	lint ans = 5e18;
	for(int i = 0; i < N; i++){
		for(int j = i + 1; j < N; j++){
			for(int k = 0; k < N; k++){
				for(int l = k + 1; l < N; l++){
					lint x1 = xa[i], x2 = xa[j], y1 = ya[k], y2 = ya[l];
					int c = 0;
					for(int m = 0; m < N; m++){
						if(x1 <= x[m] && x[m] <= x2 && y1 <= y[m] && y[m] <= y2) c++;
					}
					if(c >= K) ans = min(ans, (x2 - x1) * (y2 - y1));
				}
			}
		}
	}
	cout << ans << endl;
}