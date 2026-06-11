#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;

int maxTime(int x) {
	return (x+9) / 10 * 10;
} 
int remTIme(int x) {
	return maxTime(x) - x;
}
int main() {
	//int a,b,c,d,e;
	//cin >> a >> b >> c >> d >> e;
	int ans = 0;
	int time[5];
	int rem = 0;
	rep(i,5) {
		cin >> time[i];
		ans += maxTime(time[i]);
		rem = max(rem, remTIme(time[i]));
	}
	cout << ans - rem << endl;

	return 0;
}