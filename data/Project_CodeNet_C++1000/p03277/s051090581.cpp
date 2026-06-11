#include <iostream>
using namespace std;

int ft[200005];

void gnk(int i) {
	while(i <= 200001) {
		++ft[i];
		i += (i & -i);
	}
}

int pj(int i) {
	int tp = 0;
	while(i) {
		tp += ft[i];
		i -= (i & -i);
	}
	return tp;
}

int n, a[100005], b[100005], fp;
long long rr, N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	N = n;
	N *= n + 1;
	N /= 4;
	++N;
	for(int i = 1; i  <= n; ++i) {
		cin >> a[i];
	}
	int l = 1, r = 1e9, m;
	while(l <= r) {
		for(int i = 1; i <= 200001; ++i) {
			ft[i] = 0;
		}
		m = (l + r) / 2;
		for(int i  = 1; i <= n; ++i) {
			if(a[i] <= m) {
				b[i] = 1;
			} else {
				b[i] = 0;
			}
		}
		gnk(1 + 1e5);
		rr = 0;
		int g = 0;
		for(int i = 1; i <= n; ++i) {
			if(b[i]) {
				++g;
			} else {
				--g;
			}
			rr += pj(g + 1e5);
			gnk(g +1e5 + 1);
		}
		if(rr >= N) {
			fp = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	cout << fp << endl;
	return 0;
}