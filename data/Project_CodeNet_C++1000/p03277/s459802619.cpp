#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
class fenwick_tree {
	const int n;
	vector<T> data;
public:
	fenwick_tree(int n_) : n(n_), data(n + 1) {}
	T find(int p) const {
		T res = 0;
		while (p > 0) {
			res += data[p];
			p -= p & -p;
		}
		return res;
	}
	void add(int p, T val) {
		++p;
		while (p <= n) {
			data[p] += val;
			p += p & -p;
		}
	}
};

int main()
{
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	ll k = (ll)N * (N + 1) / 2;
	int lb = 0, ub = 1e9;
	while (ub - lb > 1) {
		int c = (lb + ub) >> 1;
		vector<int> sum(N + 1); sum[0] = N;
		for (int i = 0; i < N; i++) {
			sum[i + 1] = sum[i] + (a[i] <= c ? 1 : -1);
		}
		ll cnt = 0;
		fenwick_tree<int> ft(N + N + 1);
		for (int i = 0; i <= N; i++) {
			cnt += ft.find(sum[i]);
			ft.add(sum[i], 1);
		}
		(cnt * 2 > k ? ub : lb) = c;
	}
	cout << ub << endl;
	return 0;
}
