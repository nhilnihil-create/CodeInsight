
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
	int N; cin >> N;
	vector<int> T(N + 1, 0), X(N + 1, 0), Y(N + 1, 0);
	for (int i = 1; i < N + 1; ++i) {
		cin >> T.at(i) >> X.at(i) >> Y.at(i);
	}

	for (int i = N; i >= 1; --i) {
		int distance = abs(X.at(i) - X.at(i - 1)) + abs(Y.at(i) - Y.at(i - 1));
		int dt = T.at(i) - T.at(i - 1);
		if (distance > dt) {
			cout << "No" << endl;
			return 0;
		}
		if (distance % 2 != dt % 2) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}