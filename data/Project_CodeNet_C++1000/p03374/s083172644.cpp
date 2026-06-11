#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

int func(int N, const vector<pair<int,int>> &y, const vector<pair<int, int>> &z) {
	vector<int> A(N), B(N), C(N + 1);

	C[0] = 0;
	for(int i = 0; i < N; ++i) {
		A[i] = y[i].second - y[i].first;
		B[i] = z[i].second - z[i].first;

		if(i > 0) {
			A[i] += A[i - 1] + y[i - 1].first;
			B[i] += B[i - 1] + z[i - 1].first;
		}
		C[i + 1] = max(C[i], B[i]);
	}

	int res = 0;
	for(int i = 0; i < N; ++i) {
		res = max(res, A[i]);

		int t = A[i] - y[i].first + C[N - i - 1];
		res = max(res, t);
	}
	return res;
}

signed main(){
	int N, C;
	cin >> N >> C;
	vector<int> x(N), v(N);
	vector<pair<int,int>> y(N), z(N);
	for(int i = 0; i < N; ++i) {
		cin >> x[i] >> v[i];
		y[i] = make_pair(x[i], v[i]);
		z[i] = make_pair(C - x[i], v[i]);
	}
	reverse(ALL(z));
	int res = max(func(N, y, z), func(N, z, y));
	cout << res << endl;

	return 0;
}
