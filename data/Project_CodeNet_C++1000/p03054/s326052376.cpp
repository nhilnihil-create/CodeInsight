#include <bits/stdc++.h>
using namespace std;

int H, W, N; 
string T, A;
int R, C;

bool check(int l, int s, char add, char sub) {
	int mi = 1, ma = l;
	for (int i = N-1; i >= 0; i--) {
		if (A[i] == add) {
			mi--;
		} else if (A[i] == sub) {
			ma++;
		}
		mi = max(mi, 1), ma = min(ma, l);
		if (T[i] == add) {
			ma--;
		} else if (T[i] == sub) {
			mi++;
		}
		if (mi > ma) return false;
	}
	return mi <= s && s <= ma;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> H >> W >> N;
	cin >> R >> C;
	cin >> T >> A;
	if (check(H, R, 'D', 'U') && check(W, C, 'R', 'L')) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}
