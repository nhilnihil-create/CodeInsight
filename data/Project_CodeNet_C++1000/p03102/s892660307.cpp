#include <iostream>
#include <vector>


#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
	int n, m, c;
	cin >> n >> m >> c;
	vector<int> b(m);
	vector<vector<int>> a(n, vector<int>(m));
	int count = 0;

	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			sum += a[i][j] * b[j];
		}
		if (sum + c > 0)count++;
	}

	cout << count << endl;
	return 0;
}
