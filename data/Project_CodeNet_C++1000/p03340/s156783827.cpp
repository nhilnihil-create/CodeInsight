#include <iostream>
using namespace std;

typedef long long ll;

const int N = 2e5 + 5, C = 22;
ll n, ans;
int a[N];
int cnt[C], b;

void add(int d) {
	for (int i = 0; i < C; i++)
		if ((d >> i) & 1) {
			cnt[i]++;
			b += (cnt[i] == 2);
		}
}

void del(int d) {
	for (int i = 0; i < C; i++)
		if ((d >> i) & 1) {
			cnt[i]--;
			b -= (cnt[i] == 1);
		}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	add(a[0]);
	int l = 0, r = 0;
	while (l < n) {
		while (b == 0 && r < n) {
			r++;
			add(a[r]);
		}

		ans += r - l;

		del(a[l]);
		l++;
	}

	cout << ans << "\n";
	return 0;
}
