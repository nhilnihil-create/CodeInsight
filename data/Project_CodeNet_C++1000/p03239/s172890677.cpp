#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, T;
vector<int> P;

void input_init(void) {
	cin >> N >> T;
	for (int i = 0; i < N; ++i) {
		int c, t;
		cin >> c >> t;
		if (t <= T)
			P.push_back(c);
	}
}

int main(void) {
	input_init();
	if (P.size() == 0)
		cout << "TLE" << '\n';
	else {
		int ans = *min_element(P.begin(), P.end());
		cout << ans << '\n';
	}
	return 0;
}
