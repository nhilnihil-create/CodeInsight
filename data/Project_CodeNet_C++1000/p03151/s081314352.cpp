#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 100010;

int n, cnt;
long long sum1, sum2, ans;
int a[N], b[N], d[N];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	int p = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] > b[i]) {
			sum1 += (a[i] - b[i]);
			d[++p] = (a[i] - b[i]);
		}
		if (a[i] < b[i]) {
			sum2 += (b[i] - a[i]);
			cnt++;
		}
	}
	if (!cnt) cout << 0 << endl;
	else if (sum1 < sum2) cout << -1 << endl;
	else {
		sort(d + 1, d + 1 + p);
		
		int i;
		for(i = p; i >= 1; i--){
			ans += d[i];
			if (ans >= sum2) break;
		}
		cout << cnt + p - i + 1 << endl;
	}
	
	return 0;
}