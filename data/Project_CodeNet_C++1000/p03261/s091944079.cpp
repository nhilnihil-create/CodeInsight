#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<string>W(N);
	set<string>st;
	for (int n = 0;n<N;++n) {
		cin >> W[n];
		st.insert(W[n]);
	}
	if (N != st.size()) {
		cout << "No"<<endl;
		return 0;
	}
	for (int n = 0; n < N - 1; ++n) {
		if (W[n][W[n].size()-1]  != W[n+1][0]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}