

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
	int N; cin >> N;
	vector<int> T(N + 1, 0), X(N + 1, 0), Y(N + 1, 0);
	bool ok = 1;
	for (int i = 1; i <= N; ++i) {
		cin >> T[i] >> X[i] >> Y[i];
		int dt = T[i] - T[i - 1];
		int dx = abs(X[i] - X[i - 1]);
		int dy = abs(Y[i] - Y[i - 1]);
		if (dx + dy <= dt && dt % 2 == (dx + dy) % 2) {}
		else ok = 0;
	}
	cout << (ok ? "Yes" : "No") << endl;
}
