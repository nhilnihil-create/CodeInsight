#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M, X, Y;
	cin >> N >> M >> X >> Y;
	int XMAX = X, YMIN = Y;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		XMAX = max(x, XMAX);
	}
	for (int i = 0; i < M; i++) {
		int y;
		cin >> y;
		YMIN = min(y, YMIN);
	}
	cout << (XMAX < YMIN ? "No War" : "War") << endl;
}