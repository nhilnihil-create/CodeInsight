#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
	int H, W, D, A, Q, L, R;
	cin >> H >> W >> D;
	vector<pair<int, int>> a(H * W);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> A;
			a[A - 1].first = i;
			a[A - 1].second = j;
		}
	}
	cin >> Q;
	vector<int> b(H * W);
	for (int i = D; i < H * W; i++) {
		b[i] += abs(a[i - D].first - a[i].first);
		b[i] += abs(a[i - D].second - a[i].second);
		b[i] += b[i - D];
	}
	for (int i = 0; i < Q; i++) {
		cin >> L >> R;
		cout << b[R - 1] - b[L - 1] << endl;
	}
}