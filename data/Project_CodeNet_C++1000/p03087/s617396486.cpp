#include "bits/stdc++.h"
using namespace std;

int main() {
	int N,Q;
	string S;
	cin >> N>>Q >>S;
	vector<int>Memo;
	for (int n = 0;n<N-1;++n) {
		if ('A' == S[n]&&'C' ==S[n + 1]) {
			Memo.push_back(n + 1);
		}
	}
	for (int n = 0;n<Q;++n) {
		int l, r;
		cin >> l >> r; 
		cout << lower_bound(Memo.begin(), Memo.end(), r) - lower_bound(Memo.begin(), Memo.end(), l) << endl;
	}
}
