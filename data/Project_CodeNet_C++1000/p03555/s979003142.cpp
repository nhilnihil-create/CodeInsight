// ABC077A - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	string a, b;
	cin >> a >> b;

	if ((a[0] == b[2])&&(a[1] == b[1])&&(b[0] == a[2])) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}
