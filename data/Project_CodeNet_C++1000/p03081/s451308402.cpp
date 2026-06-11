#include <bits/stdc++.h>
using namespace std;
typedef pair<char, bool> pi; //0 left, 1 right
#define f first
#define s second

long long n, q;
pi spells[200005];
string ss;
long long upper, lower, mid, ri, le;

long long bsta(long long guess) {
	long long pos = guess;
	for (long long i = 0; i < q; i++) {
		if (spells[i].f == ss[pos]) {
			if (spells[i].s) pos++;
			else pos--;
		}
		if (pos < 0) return -1; //Felong long off left side
		else if (pos >= n) return 1; //Felong long off right side
	}
	return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> q >> ss;
	for (long long i = 0; i < q; i++) {
		char x;
		cin >> spells[i].f >> x;
		if (x == 'L') spells[i].s = 0;
		else spells[i].s = 1;
	}
	lower = -1, upper = n;
	while (upper - lower > 1) {
		mid = ((upper + lower)>>1);
		if (bsta(mid) == -1) lower = mid;
		else upper = mid;
	}
	le = upper;
	lower = -1, upper = n;
	while (upper - lower > 1) {
		mid = ((upper + lower)>>1);
		if (bsta(mid) == 1) upper = mid;
		else lower = mid;
	}
	ri = lower;
	cout << ri - le + 1;
}
