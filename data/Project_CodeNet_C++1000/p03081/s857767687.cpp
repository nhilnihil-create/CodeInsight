#include<bits/stdc++.h>
using namespace std;

char t[1 << 18], d[1 << 18];
int n, q; string s;

int sta(int x) {
	for(int i = 0; i < q; i++) {
		if (s[x] == t[i]) {
			if (d[i] == 'L')x--;
			else x++;
		}
		if (x < 0)return 1;
		else if (x >= n)return 2;
	}
	return 0;
}

int main() {
	cin >> n >> q >> s;
	for(int i = 0; i < q; i++) {
		cin >> t[i] >> d[i];
	}
	int le = 0, ri = n;
	while (ri - le > 1) {
		int mid = (le + ri) / 2;
		if (sta(mid) == 1)le = mid;
		else ri = mid;
	}
	int cle = 0, cri = n;
	while (cri - cle > 1) {
		int mid = (cle + cri) / 2;
		if (sta(mid) == 2)cri = mid;
		else cle = mid;
	}
	int ans = cle - ri + 1;
	if (ans < 0)ans = 0;
	cout << ans << endl;
}
