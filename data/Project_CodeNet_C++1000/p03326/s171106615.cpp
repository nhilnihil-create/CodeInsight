#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int64_t>> v(3, vector<int64_t>(0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			int64_t n;
			cin >> n;
			v.at(j).push_back(n);
		}
	}

	int64_t ans = 0;
	for (int bit = 0; bit < (1 << 3); bit++) {
		bitset<3> bs(bit);

		vector<int64_t> vec(N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 3; j++) {
				if (bs[j]) vec.at(i) += v.at(j).at(i);
				else vec.at(i) += -v.at(j).at(i);
			}
		}

		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());

		int64_t sum = 0;
		for (int i = 0; i < M; i++) sum += vec.at(i);
		ans = max(ans, sum);
	}

	cout << ans << endl;
}