#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

	int N, A, B, C;
	cin >> N >> A >> B >> C;

	vector<int> l(N);

	for(int i = 0; i < N; i++) {
		cin >> l[i];
	}

	int min = 10000000;

	for(int a = 1; a < (1 << N); a++) {
		int ca = -10;

		vector<int> X;
		int x = 0;

		for(int i = 0; i < N; i++) {
			if(a & (1 << i)) {
				X.push_back(l[i]);
			} else {
				x += l[i];
				ca += 10;
			}
		}

		ca += abs(A - x);

		if(X.size() >= N) continue;

		for(int b = 1; b < (1 << X.size()); b++) {
			int cb = -10;

			vector<int> Y;
			int y = 0;

			for(int i = 0; i < X.size(); i++) {
				if(b & (1 << i)) {
					Y.push_back(X[i]);
				} else {
					y += X[i];
					cb += 10;
				}
			}

			cb += abs(B - y);

			if(Y.size() >= X.size()) continue;

			for(int c = 1; c < (1 << Y.size()); c++) {
				int cc = -10;

				int z = 0;

				for(int i = 0; i < Y.size(); i++) {
					if(c & (1 << i)) {
						z += Y[i];
						cc += 10;
					}
				}

				cc += abs(C - z);

				if(ca + cb + cc < min) {
					min = ca + cb + cc;
				}
			}
		}
	}

	cout << min << endl;
}