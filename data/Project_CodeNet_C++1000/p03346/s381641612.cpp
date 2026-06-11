#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int N;
	cin >> N;
	vector<int> P(N);
	for(auto &p : P) cin >> p;

	vector<int> num(N+2, 0);
	for(int i=N-1;i>=0;i--) {
		num[P[i]] = num[P[i]+1] + 1;
	}
	cout << N - *max_element(num.begin(), num.end()) << endl;
}