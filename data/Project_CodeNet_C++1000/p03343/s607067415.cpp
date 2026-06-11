#include <bits/stdc++.h>
#define sp ' '
#define nyan "(=^・ω・^=)"
#define mkp make_pair
#define intmax 2147483647
#define llmax 9223372036854775807
#define lP pair<ll,ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;
const int mod = 1000000007;

int N, K, Q, A[2000], a[2001], res;


int main() {
	cin >> N >> K >> Q;
	for (int i = 0; i != N; ++i) {
		cin >> A[i];
		a[i] = A[i];
	}
	a[N] = intmax;
	sort(a, a + N);
	res = intmax;
	for (int i = 0; i != N - Q + 1; ++i) {
		int l = i + Q - 2;
		int r = N;
		while (l + 1 != r) {
			int k = (l + r) / 2;
			int E869120 = 0, square1001 = 0, Segtree = 0;
			for (int j = 0; j != N; ++j) {
				if (a[i] <= A[j] && A[j] <= a[k])
					++square1001;
				else if (a[k] < A[j])
					++Segtree;
				else {
					E869120 += max(0, square1001 + min(0, Segtree - K + 1));
					square1001 = Segtree = 0;
				}
			}
			E869120 += max(0, square1001 + min(0, Segtree - K + 1));
			if (E869120 >= Q)
				r = k;
			else
				l = k;
		}
		res = min(res, a[r] - a[i]);
	}
	cout << res << endl;
	return 0;
}