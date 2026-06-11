#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	if (N<=999) {
		cout << "ABC" << endl;
	} else if (N>=1000) {
		cout << "ABD" << endl;
	}
	return 0;
}
