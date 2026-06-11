#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N, H;
	cin >> N >> H;

	vector<int> a(N), b(N);
	for (int i = 0; i < N; i++) {
		cin >> a.at(i) >> b.at(i);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int cnt = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (b.at(i) <= a.at(N - 1)) break;

		if (H <= 0) {
			cout << cnt << endl;
			return 0;
		}
		else {
			cnt++;
			H -= b.at(i);
		}
	}

	if (H <= 0) {
		cout << cnt << endl;
	}
	else {
		int n= H / a.at(N - 1);
		if (a.at(N - 1) * n == H) {
			cnt += n;
		}
		else {
			cnt += n + 1;
		}

		cout << cnt << endl;
	}
}