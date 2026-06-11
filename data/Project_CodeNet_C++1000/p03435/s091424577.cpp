#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    
	const int p = 3;
	vector<vector<int>> c(p, vector<int>(p));
	for (int i = 0; i < p; i++) {
		for (int  j = 0; j < p; j++) {
			cin >> c[i][j];
		}
	}
	int b0 = c[0][0];
	int b1 = c[0][1];
	int b2 = c[0][2];
	bool can = true;
	if (!(c[1][0] - b0 == c[1][1] - b1 && c[1][1] - b1 == c[1][2] - b2)) can = false;
	if (!(c[2][0] - b0 == c[2][1] - b1 && c[2][1] - b1 == c[2][2] - b2)) can = false;
	if (can) cout << "Yes" << endl;
	else cout << "No" << endl;
    return 0;
}