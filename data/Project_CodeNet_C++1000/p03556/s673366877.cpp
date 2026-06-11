// ABC077B - Around Square

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

int main() {
	ull N;
	cin >> N;

	ull ans = 1;

	while (1) {
		if (ans * ans > N) {
			cout << (ans - 1) * (ans - 1) << endl;
			return 0;
		}
		++ans;
	}

	return 0;
}
