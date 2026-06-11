#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int INF = 1000000000;

int main() {
	int n;
	vector<int> a(3);
	cin >> n >> a[0] >> a[1] >> a[2];
	int l[n];
	for (int i = 0; i < n; i++) cin >> l[i];
	
	int p = pow(4, n);
	int ans = INF;
	for (int i = 0; i < p; i++) {
		int t[n];
		{	
			int tmp = i;
			for (int j = 0; j < n; j++) {
				t[j] = tmp % 4;
				tmp /= 4;
			}
		}

		int now = 0;
		int b[3] = {0};
		for (int i = 0; i < n; i++) {
			if (t[i] == 3) continue;
			if (b[t[i]] == 0) b[t[i]] += l[i];
			else {
				b[t[i]] += l[i];
				now += 10;
			}
		}
		if (b[0]==0 || b[1]==0 || b[2]==0) continue;
		for (int i = 0; i < 3; i++) now += abs(a[i]-b[i]);
		ans = min(ans, now);	
	}
	cout << ans << endl;
	return 0;
}