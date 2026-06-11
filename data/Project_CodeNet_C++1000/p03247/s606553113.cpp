#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long


signed main(signed argc, char** argv){
	int N;
	cin >> N;
	vector<int> X(N), Y(N);
	for(int i = 0; i < N; ++i) {
		cin >> X[i] >> Y[i];
	}
	
	bool g = true;
	int z = (abs(X[0]) + abs(Y[0])) % 2;
	for(int i = 0; i < N; ++i) {
		g = g && (abs(X[i]) + abs(Y[i])) % 2 == z;
	}
	if (!g) {
		cout << -1 << endl;
		return 0;
	}
	bool f = (X[0] + Y[0]) % 2 == 0;
	if(f) {
		for(int i = 0; i < N; ++i) {
			X[i]--;
		}
	}
	const int m = 31;
	cout << (f ? m + 1: m) << endl;
	if(f) cout << 1 << " ";
	for(int i = 0; i < m; ++i) {
		cout << (1LL << i) << (i == m - 1 ? "\n": " ");
	}
	for(int i = 0; i < N; ++i) {
		int U = (X[i] + Y[i] + (1LL << m) - 1) / 2;
		int V = (X[i] - Y[i] + (1LL << m) - 1) / 2;
		int x = 0, y = 0;
		if(f){
			cout << "R";
		}
		for(int i = 0; i < m; ++i) {
			if(((U >> i) & 1) && ((V >> i) & 1)) {
				cout << "R";
				x += 1LL << i;
			} else if(((U >> i) & 1) && !((V >> i) & 1)) {
				cout << "U";
				y += 1LL << i;
			} else if(!((U >> i) & 1) && ((V >> i) & 1)) {
				cout << "D";
				y -= 1LL << i;
			} else if(!((U >> i) & 1) && !((V >> i) & 1)) {
				cout << "L";
				x -= 1LL << i;
			}
		}
		if(x != X[i] || y != Y[i]) {
			cout << x << " " << y << endl;
			cout << "dead" << endl;
		}
		cout << endl;
	}
	return 0;
}
