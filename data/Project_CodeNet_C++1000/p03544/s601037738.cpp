#include"bits/stdc++.h"
using namespace std;

int64_t luca(vector<int64_t>& ans,int n) {
	if (ans.at(n)) return ans.at(n);
	return ans.at(n) = luca(ans, n - 1) + luca(ans, n - 2);
}

int main() {
	int N; cin >> N;
	
	vector<int64_t> ans(N+1, 0);
	ans.at(0) = 2;
	ans.at(1) = 1;
	cout << luca(ans, N) << endl;
}