//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

int n, k;

void to() {
	for (int i = 0; i < (1 << n); i++)
		if (i != k) cout << i << ' ';
	cout << k << ' ';
}
void torev() {
	for (int i = (1 << n) - 1; ~i; i--)
		if (i != k) cout << i << ' ';
	cout << k << ' ';
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	if (k >= (1 << n))
		return cout << -1 << endl, 0;
	if (n == 1) {
		if (k == 1)
			return cout << -1 << endl, 0;
		else
			return cout << "0 1 1 0" << endl, 0;
	}
	to();
	torev();
	return 0;
}
