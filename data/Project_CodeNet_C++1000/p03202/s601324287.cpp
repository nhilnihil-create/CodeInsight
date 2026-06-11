#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, A[200009];

bool solve(int M) {
	vector<pair<int, int>>vec;

	vec.push_back(make_pair(1, 0));
	for (int i = 0; i < N; i++) {
		if (vec[vec.size() - 1].first < A[i]) {
			vec.push_back(make_pair(A[i], 1));
		}
		else {
			while (vec.size() >= 1 && vec[vec.size() - 1].first > A[i]) vec.pop_back();
			if (vec[vec.size() - 1].first == A[i]) vec[vec.size() - 1].second++;
			else vec.push_back(make_pair(A[i], 2));
		}

		// 単調増加になった
		while (vec.size() >= 2 && vec[vec.size() - 1].second == M + 1) {
			int Z = vec.size();
			if (vec[Z - 2].first + 1 == vec[Z - 1].first) {
				vec[Z - 2].second++; vec.pop_back();
			}
			else {
				int RANK = vec[Z - 1].first - 1; vec.pop_back();
				vec.push_back(make_pair(RANK, 1));
			}
		}

		if (i == 0) vec[0].second = 1;
	}
	if (vec[0].second > M) return false;
	return true;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) { cin >> A[i]; }
	bool flag = true;
	for (int i = 0; i < N - 1; i++) {
		if (A[i] >= A[i + 1]) flag = false;
	}
	if (flag == true) {
		cout << "1" << endl;
		return 0;
	}

	int L = 2, R = (1 << 30), M, maxn = (1 << 30);
	for (int i = 0; i < 40; i++) {
		M = (L + R) / 2;
		bool t = solve(M);
		if (t == true) { maxn = min(maxn, M); R = M; }
		else { L = M; }
	}
	cout << maxn << endl;
	return 0;
}