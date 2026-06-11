#include "bits/stdc++.h"
using namespace std;

int main() {
	long long H, W, N, Cur = 0, MIN;
	vector<pair<long long, long long> > V;
	cin >> H >> W >> N;
	MIN = H;
	V.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> V[i].first >> V[i].second;
		V[i].first--, V[i].second--;
	}
	sort(V.begin(), V.end());
	for (int i = 0; i < N; i++) {
		if (V[i].first - V[i].second < Cur) continue;
		if (V[i].first - V[i].second == Cur) Cur++;
		else MIN = min(MIN, V[i].first);
	}
	cout << MIN << endl;
}