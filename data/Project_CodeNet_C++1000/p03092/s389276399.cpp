#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxN = 5000 + 5;
const LL maxA = 1000000000 + 233;
int n, p[maxN];
LL A, B;
LL f[maxN];

int main() {
	cin >> n >> A >> B;
	p[0] = 0; p[n + 1] = n + 1;
	for(int i = 1; i <= n; ++i) cin >> p[i];
	f[0] = 0;
	for(int i = 1; i <= n + 1; ++i) {
		int mx = -1;
		int bigger = 0, smaller = 0;
		f[i] = maxN * maxA;
		for(int j = i - 1; j >= 0; --j) {
			if(p[j] > p[i]) {
				bigger ++;
			} else {
				if(p[j] > mx) {
					mx = p[j];
					f[i] = min(f[i], f[j] + bigger * A + smaller * B);
				}
				smaller ++;
			}
		}
	}
	cout << f[n + 1] << endl;
	return 0;
}
