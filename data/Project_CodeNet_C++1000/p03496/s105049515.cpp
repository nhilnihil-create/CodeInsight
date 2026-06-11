#include <bits/stdc++.h>

using namespace std;

#define rep(i, a) for (int i = 0; i < a; i++)
#define reps(i, a, b) for (int i = a; i < b; i++)

int n;
long long a[50];

void culcp() {
	rep(i, n-1) {
		cout << i+1 << " " << i+2 << endl;
	}
}

void culcm() {
	rep(i, n-1) {
		cout << n-i << " " << n-i-1 << endl;
	}
}

void plusma(int mai) {
	rep(i, n) {
		cout << mai << " " << i+1 << endl;
	}
	culcp();
}
	
void plusmi(int mii) {
	rep(i, n) {
		cout << mii << " " << i+1 << endl;
	}
	culcm();
}

int main()
{
	cin >> n;
	rep(i, n) cin >> a[i];
	long long mi, ma;
	int mai, mii;
	mi = ma = a[0];
	mai = mii = 1;
	rep(i, n) {
		if (mi > a[i]) mi = a[i], mii = i+1;
		if (ma < a[i]) ma = a[i], mai = i+1;
	}
	if (mi >= 0) {
		cout << n-1 << endl;
		culcp();
	} else if (ma <= 0) {
		cout << n-1 << endl;
		culcm();
	} else if (ma > -mi) {
		cout << 2*n-1 << endl;
		plusma(mai);
	} else {
		cout << 2*n-1 << endl;
		plusmi(mii);
	}
	return 0;
}