#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>
#include<iomanip>

int main() {
	int n, k;
	cin >> n >> k;
	double ans(0);
	int omote = 1;
	int t = 1;
	int cnt(0);
	
	while (1) {
		t *= 2;
		cnt++;
		if (t >= k) {
			break;
		}
	}
	omote = cnt;
	for (int i = 1; i <= n; ++i) {
		if (i * pow(2, omote - 1) >= k)omote -= 1;
		if (omote <= 0)omote = 0;
		ans += 1.0 / double(n) * pow(0.5, omote);
		
	}
	cout << fixed <<setprecision(12) << ans;
	return 0;
}