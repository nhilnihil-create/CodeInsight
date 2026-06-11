#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll x;
ll a[202020];

__int128_t lol(int u) {
	__int128_t w = 0;
	for (int i = n; i >= n-u+1; i--) {
		w += x;
		w += a[i];
		int k = 1;
		int j = i;
		while (true) {
			w += x;
			if (j-u >= 1) {
				j -= u;
				w += (__int128_t)(a[j+u]-a[j])*(k+1)*(k+1);
			} else {
				w += (__int128_t)a[j]*(k+1)*(k+1);
				break;
			}
			k++;
		}
	}
	return w;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int k = 0;
	for (int b = n/2; b >= 1; b /= 2) {
		while (k+b+1 <= n && lol(k+b) > lol(k+b+1)) k += b;
	}
	cout << (ll)lol(k+1) << "\n";
}
