// ABC077B - 

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	ull N;
	cin >> N;

	map<ull, ull> t;

	for (ull i = 1; i <= 100000; i++) {
		t[i * i] = 1;
	}

	for (ull i = N; i >= 1; i--) {
		if (t[i] == 1) {
			cout << i << endl;
			return 0;
		}
	}


	return 0;
}
