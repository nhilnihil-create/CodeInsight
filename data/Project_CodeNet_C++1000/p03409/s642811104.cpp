#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	vector<int>B(N);
	vector<pair<int, int>>AB(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
		AB[i] = make_pair(A[i], B[i]);
	}
	vector<int>C(N);
	vector<int>D(N);
	vector<pair<int, int>>CD(N);
	for (int i = 0; i < N; ++i) {
		cin >> C[i] >> D[i];
		CD[i] = make_pair(C[i], D[i]);
	}
	sort(AB.begin(), AB.end());
	sort(CD.begin(), CD.end());

	vector<bool>used(N, false);
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		pair<int, int>B = CD[i];
		int maxy = -1;
		int index = -1;
		for (int j = 0; j < N; ++j) {
			if ((false == used[j]) && (AB[j].second < B.second) && (AB[j].first < B.first) && (maxy < AB[j].second)) {
				index = j;
				maxy = AB[j].second;
			}
		}
		if (-1 != index) {
			used[index] = true;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}