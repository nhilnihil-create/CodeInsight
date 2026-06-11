// In The Name Of GOD
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3 * 100 + 3;

char mat[MAXN][MAXN];

bool CheckTheColumn(int A, int n);

int main() {
	int n, ans = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> mat[i][j];
	for(int i = 0; i < n; i++)
		ans += CheckTheColumn(i, n) * n;
	cout << ans;
}

bool CheckTheColumn(int A, int n) {
	//cerr << "CheckTheColumn " << A << endl;
	for (int c = 0, i = A; c < n; i++, c++, i %= n) {
		for (int j = 0, k = A; j < n; j++, k++, k %= n) {
		// n - c, n - j --> n - c + A, n - j
			if(mat[i][j] != mat[k][c])
				return false;
		}
	}
	return true;
}

