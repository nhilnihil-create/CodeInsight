#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int N, M, X, Y;
	cin >> N >> M >> X >> Y;
	vector<int> x(N), y(M);
	for (int i = 0; i < N; i++) cin >> x[i];
	for (int i = 0; i < M; i++) cin >> y[i];
	string ans = "War";
	for (int Z = X + 1; Z <= Y; Z++) {
		bool ok = true;
		for (int i = 0; i < N; i++) {
			if (x[i] >= Z) ok = false;
		}
		for (int j = 0; j < M; j++) {
			if (y[j] < Z) ok = false;
		}
		if (ok) ans = "No War";
	}
	cout << ans << endl;
	return 0;
}