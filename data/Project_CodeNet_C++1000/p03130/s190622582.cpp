#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
	vector<int> c(4);

	rep(i,3) {
		int a,b;
		cin >> a >> b;
		++c.at(--a), ++c.at(--b);
	}

	rep(i,4)
		if(c.at(i) > 2) {
			cout << "NO" << endl;
			return 0;
		}
	cout << "YES" << endl;
}