#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	int map[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}
	int a[3], b[3];
	for (int i = 0; i < 3; i++) {
		int ans = 200;
		for (int j = 0; j < 3; j++) {
			a[i] = min(ans, map[i][j]);
			ans = a[i];
		}
	}

	for (int i = 0; i < 3; i++) {
		b[i] = map[0][i] - a[0];
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[i] + b[j] != map[i][j]) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}


