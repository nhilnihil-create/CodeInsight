#include <bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

int N;
ll X, x[200000], res, s[200001];

int main() {
	cin >> N >> X;
	for (int i = 0; i < N; ++i) {
		cin >> x[i];
	}
	for (int i = 0; i < N; ++i) {
		s[i + 1] = s[i] + x[i];
	}
	res = llmax;
	for (int i = 1; i <= N; ++i) {
		ll t = X*(i + N) + (s[N] - s[N - i]) * 2;
		ll c = 3;
		for (int j = N; j > 0; j -= i) {
			t += c*(s[j] - s[max(0, j - i)]);
			if (t >= 1e17) {
				break;
			}
			c += 2;
		}
		res = min(res, t);
	}
	cout << res << endl;
}