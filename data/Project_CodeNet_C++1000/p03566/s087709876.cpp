#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

int main() {
	int n, T[100]; cin >> n;
	double V[100];
	for (int i = 0; i < n; i++)cin >> T[i];
	for (int i = 0; i < n; i++)cin >> V[i];

	int t = 0; double vl[40005], vr[40005];
	vl[0] = 0;
	for (int i = 0; i < n; i++)for (int j = 0; j < 2 * T[i]; j++) {
		vl[t + 1] = min(vl[t] + 0.5, V[i]); t++;
	}

	vr[t] = 0;
	for (int i = n - 1; i >= 0; i--)for (int j = 0; j < 2 * T[i]; j++) {
		vr[t - 1] = min(vr[t] + 0.5, V[i]); t--;
	}

	double ans = 0; t = 0;
	for (int i = 0; i < n; i++)for (int j = 0; j < 2 * T[i]; j++) {
		ans += (min(vl[t], vr[t]) + min(vl[t + 1], vr[t + 1])) / 4; t++;
	}
	cout << fixed << setprecision(14) << ans << endl;

	return 0;
}