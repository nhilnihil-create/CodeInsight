#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

vector<int> calc(vector<int> &x, vector<int> &v) {
	int N = x.size();
	vector<int> res(N+1);

	res[0] = 0;
	int sum = v[0];
	for(int i = 1; i <= N; ++i) {
		res[i] = max(res[i-1], sum - x[i-1]);
		sum += v[i];
	}
	return res;
}

signed main(){
	int N, C;
	cin >> N >> C;
	vector<int> x(N), v(N);
	for(int i = 0; i < N; ++i) {
		cin >> x[i] >> v[i];
	}

	vector<int> rx = x, rv = v;
	for(int i = 0; i < N; ++i) rx[i] = C - rx[i];
	reverse(ALL(rx));
	reverse(ALL(rv));

	vector<int> mx = calc(x, v), rmx = calc(rx, rv);

	int res = 0;
	for(int k = 0; k < 2; ++k) {
		res = max(res, mx[N]);
		for(int i = 0; i < N; ++i) {
			res = max(res, mx[i+1] + rmx[N - i - 1] - x[i]);
		}
		swap(x, rx);
		swap(v, rv);
		swap(mx, rmx);
	}
	cout << res << endl;

	return 0;
}
