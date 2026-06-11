#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, L, R;
	double count = 0, ans = 0;
	pair<double, double> P[100];
	map<double, double> mpL, mpR, mp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> P[i].first;
		count += P[i].first;
		if (i != 0) P[i].first += P[i - 1].first;
	}
	for (int i = 0; i < N; i++) {
		cin >> P[i].second;
	}
	L = 0, R = N - 1;
	mpL[0] = 0, mpR[count] = 0;
	for (double i = 0.5; i <= count; i += 0.5) {
		double maxS = P[L].second;
		mpL[i] = mpL[i - 0.5] + 0.5;
		mpL[i] = min(mpL[i], maxS);
		if (i == P[L].first) L++;
	}
	for (double i = count - 0.5; i >= 0; i -= 0.5) {
		double maxS = P[R].second;
		mpR[i] = mpR[i + 0.5] + 0.5;
		mpR[i] = min(mpR[i], maxS);
		if (R != 0 && i == P[R - 1].first) R--;
	}
	for (double i = 0; i <= count; i += 0.5) {
		mp[i] = min(mpL[i], mpR[i]);
	}
	for (double i = 0; i < count; i += 0.5) {
		ans += (mp[i] + mp[i + 0.5]) / 4;
	}
	printf("%.8f", ans);
}