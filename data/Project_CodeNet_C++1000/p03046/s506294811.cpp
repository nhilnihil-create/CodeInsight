#include "bits/stdc++.h"
using namespace std;

int main() {
	long long M, K;
	cin >> M >> K;
	long long lim  = ((long long)1) << M;
	if (K>= lim) {
		cout << -1 << endl;
		return 0;
	}
	if (0 == M) {
		if (0 == K) {
			cout <<"0 0"<<endl;
		}
		else {
			cout << -1 << endl;
		}
		return 0;
	}
	if (1==  M) {
		if (0 == K) {
			cout << "0 0 1 1" << endl;
		}
		else {
			cout << -1 << endl;
		}
		return 0;
	}
	vector<int>Ans;
	for (int i = 0;i<lim; ++i) {
		if (K !=i) {
			Ans.push_back(i);
		}
	}
	Ans.push_back(K);
	for (int i = lim-1;i>=0; --i) {
		if (K != i) {
			Ans.push_back(i);
		}
	}
	Ans.push_back(K);
	for (int i = 0;i<Ans.size();++i) {
		if (0 != i) {
			cout << " ";
		}
		cout << Ans[i];
	}
	return 0;
}

