#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;

ll N, a[100000];

struct BIT {
	vector<ll> bit;
	int n;

	BIT(int a) {
		n = a;
		bit.resize(n + 1);
		for (int i = 0; i < n + 1; i++)bit[i] = 0;
	}

	ll sum(int i) {
		ll s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}

	void add(int i, int x) {
		while (i <= n) {
			bit[i] += x;
			i += i & -i;
		}
	}

	ll sum(int l, int r) {
		//[l, r)
		return sum(r - 1) - sum(l - 1);
	}
};

bool f(ll value) {
	int geta = N + 1;
	BIT bit(N + geta + 20);
	ll rtn = 0;
	int Sum = 0;
	bit.add(geta, 1);
	for (int i = 0; i < N; i++) {
		Sum += (a[i] <= value ? 1 : -1);
		rtn += bit.sum(1, Sum + geta);
		bit.add(Sum + geta, 1);
	}
	if (rtn > N*(N + 1) / 4)return true;
	return false;

}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++)cin >> a[i];
	ll up = 1 << 30, lw = 0;

	while (up - 1 != lw) {
		ll mid = (up + lw) / 2;
		if (f(mid))up = mid;
		else lw = mid;
	}
	cout << up << endl;

	return 0;
}