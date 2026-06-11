#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, ANS = 0;
	vector<pair<long long, long long> > P;
	vector<pair<long long, long long> > L, R;
	vector<bool> B;
	cin >> N;
	P.resize(N);
	L.resize(N), R.resize(N), B.assign(N, true);
	for (int i = 0; i < N; i++) {
		cin >> P[i].first >> P[i].second;
		L[i] = { P[i].first, i };
		R[i] = { P[i].second, i };
	}
	sort(L.begin(), L.end(), greater<pair<long long, long long> >());
	sort(R.begin(), R.end());
	long long NOW = 0, COUNT = 0, LNOW = 0, RNOW = 0;
	if (R[0].first < 0) {
		for (int i = 0; i < N; i++) {
			if (i % 2 == 0) {
				while (RNOW < N) {
					if (B[R[RNOW].second]) {
						if (R[RNOW].first < NOW) COUNT += NOW - R[RNOW].first, NOW = R[RNOW].first;
						B[R[RNOW].second] = false;
						RNOW++;
						break;
					}
					RNOW++;
				}
			}
			else {
				while (LNOW < N) {
					if (B[L[LNOW].second]) {
						if (L[LNOW].first > NOW) COUNT += L[LNOW].first - NOW, NOW = L[LNOW].first;
						B[L[LNOW].second] = false;
						LNOW++;
						break;
					}
					LNOW++;
				}
			}
		}
		COUNT += abs(NOW);
		ANS = max(ANS, COUNT);
	}
	NOW = COUNT = LNOW = RNOW = 0;
	B.assign(N, true);
	if (L[0].first > 0) {
		for (int i = 0; i < N; i++) {
			if (i % 2 == 1) {
				while (RNOW < N) {
					if (B[R[RNOW].second]) {
						if (R[RNOW].first < NOW) COUNT += NOW - R[RNOW].first, NOW = R[RNOW].first;
						B[R[RNOW].second] = false;
						RNOW++;
						break;
					}
					RNOW++;
				}
			}
			else {
				while (LNOW < N) {
					if (B[L[LNOW].second]) {
						if (L[LNOW].first > NOW) COUNT += L[LNOW].first - NOW, NOW = L[LNOW].first;
						B[L[LNOW].second] = false;
						LNOW++;
						break;
					}
					LNOW++;
				}
			}
		}
		COUNT += abs(NOW);
		ANS = max(ANS, COUNT);
	}
	cout << ANS << endl;
}