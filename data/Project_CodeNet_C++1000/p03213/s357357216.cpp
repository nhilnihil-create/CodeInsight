#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxx = 1e5 + 7;
const int Inf = 1 << 30;
const ll INF = 1ll << 60;
int n;
int ans;
int pr[maxx];
int cnt[maxx];
int x3, x5, x15, x25, x75;

int main() {
	// 分解质因子 X = p1^x1 * p2^x2 * ... * pn^xn
	// X的因子个数 = (x1 + 1) * (x2 + 1) * ... * (xn + 1)
	// 75 --> 3 * 5 * 5 = 3 * 25 = 5 * 15 = 75
	int num = 0;
	for(int i = 2; i <= 100; i++) {
		bool chk = 1;
		for(int j = 2; j <= sqrt(i); j++) {
			if(i % j == 0) {
				chk = 0;
				break;
			}
		}
		if(chk) pr[++num] = i;
	}
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int tmp = i;
		for(int j = 1; j <= num; j++) {
			while(tmp % pr[j] == 0) {
				cnt[j]++; // 质因子指数
				tmp /= pr[j];
			}
		}
	}
	for(int i = 1; i <= num; i++) {
		if(cnt[i] >= 2) x3++;
		if(cnt[i] >= 4) x5++;
		if(cnt[i] >= 14) x15++;
		if(cnt[i] >= 24) x25++;
		if(cnt[i] >= 74) x75++;
	}
	// 3 * 5 * 5
	ans += (x5 * (x5 - 1) / 2) * (x3 - 2); // Cx5\2 * C(x3 - 2)\1
	// 3 * 25
	ans += x25 * (x3 - 1); // Cx25\1 * C(x3 - 1)\1
	// 5 * 15
	ans += x15 * (x5 - 1); // Cx15\1 * C(x5 - 1)\1
	// 75
	ans += x75; //Cx75\1
	cout << ans << endl;
	return 0;
}