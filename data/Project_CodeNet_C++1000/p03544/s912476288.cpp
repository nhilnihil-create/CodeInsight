#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll l[87];

ll lucas(int n) {
	if(l[n] != 0) {
		return l[n];
	}
	if(n == 0) {
		l[0] = 2;
		return 2;
	} else if(n == 1) {
		l[1] = 1;
		return 1;
	} else {
		l[n] = lucas(n - 2) + lucas(n - 1);
		return l[n];
	}
}
int main(void) {
	int n;
	cin >> n;
	cout << lucas(n) << endl;
}