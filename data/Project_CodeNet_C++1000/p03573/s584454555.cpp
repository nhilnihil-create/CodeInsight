#include<bits/stdc++.h>
using namespace std;
int main() {
	int a[3];
	for (int i(0); i < 3; i++) {
		cin >> a[i];
	}
	sort(a, end(a));
	if (a[0] == a[1]) {
		cout << a[2];
	}
	else if (a[0] == a[2]) {
		cout << a[1];
	}
	else {
		cout << a[0];
	}
}