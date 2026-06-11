#include <bits/stdc++.h>

using namespace std;

using ll = long long;


int main() {
	int N;
	cin >> N;
	vector<int> t(N), v(N);
	for (int i = 0; i < N; i++) {
		cin >> t[i];
		t[i] *= 2;
		if (i) t[i] += t[i-1];
	}
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		v[i] *= 2;
	}

	vector<int> res(t.back() + 1);
	for (int i = 0; i < res.size(); i++) {
		res[i] = t.back() - i;
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = t[i]; j; j--) {
			res[j] = min(res[j], t[i] + v[i+1] - j);
		}
	}
	for (int i = 0; i < N; i++) {
		int s = i ? t[i-1] : 0;
		for (int j = s; j <= t[i]; j++) {
			res[j] = min(res[j], v[i]);
		}
	}
	res[0] = 0;
	double r = 0;
	for (int i = 1; i < res.size(); i++) {
		res[i] = min(res[i], res[i-1] + 1);
		r += res[i];
	}
	cout << fixed << setprecision(12) << r / 4 << endl;
}