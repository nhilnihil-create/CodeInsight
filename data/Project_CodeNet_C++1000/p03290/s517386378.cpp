#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int p[11];
ll c[11];
ll all[11];
int main()
{
	int D;
	ll G;
	cin >> D >> G;
	for (int i = 0; i < D; i++) {
		cin >> p[i] >> c[i];
		all[i] = 100 * (i + 1) * p[i] + c[i];
	}
	ll ans = INF;
	for (int bit = 0; bit < (1 << D); bit++) {
		int point = 0;
		ll sum = 0;
		ll cnt = 0;
		int tmp = bit;
		for (int i = 0; i < D; i++) {
			if (tmp % 2 == 1) {
				sum += all[i];
				cnt += p[i];
			}
			else point = i;
			tmp /= 2;
		}
		int c = 0;
		while (sum < G) {
			if (c == p[point]) break;
			cnt++;
			sum += 100 * (point + 1);
			c++;
		}
		if (sum >= G) ans = min(ans, cnt);
	}
	cout << ans << endl;
}
