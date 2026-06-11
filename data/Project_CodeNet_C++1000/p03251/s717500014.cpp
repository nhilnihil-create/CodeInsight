#include"bits/stdc++.h"
using namespace std;

int main(){
	int N, M, X, Y;
	cin >> N >> M >> X >> Y;
	vector<int> x(N);
	vector<int> y(M);
	for (int i = 0;i < N;++i) {
		cin >> x[i];
	}
	for (int i = 0;i < M;++i) {
		cin >> y[i];
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	cout << (max(x[x.size() - 1], X) < min(y[0], Y) ? "No War" : "War") << endl;
	return 0;
}