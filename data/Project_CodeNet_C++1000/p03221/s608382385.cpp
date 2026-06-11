#include "bits/stdc++.h"
using namespace std;

int main() {
	int N , M;
	cin >> N >> M;
	vector<int>P(M);
	vector<int>Y(M);
	vector<tuple<int, int, int>> vc;
	for (int n = 0;n<M;++n) {
		cin >> P[n]>>Y[n];
		vc.emplace_back(P[n], Y[n], n);
	}
	sort(begin(vc), end(vc));
	vector<pair<int, int>>Ans(M);
	int count = 1;
	for (int n = 0; n < M; ++n) {
		//cout << get<0>(vc[i]) << " " << get<1>(vc[i]) << " " << get<2>(vc[i]) << endl;
		if (0 == n) {
		}
		else {
			if (get<0>(vc[n]) != get<0>(vc[n - 1])) {
				count = 1;
			}
		}
		Ans[get<2>(vc[n])] = make_pair(get<0>(vc[n]),count);
		count++;
	}
	for (int n = 0;n<M;++n) {
		cout << setfill('0') << right << setw(6) << Ans[n].first;
		cout << setfill('0') << right << setw(6) << Ans[n].second << endl;
	}
	return 0;
}