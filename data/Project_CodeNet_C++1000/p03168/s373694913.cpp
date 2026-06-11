#include <iostream>
#include <iomanip>
using namespace std;

const int MAXN = 3003;
double ans[MAXN][MAXN];
double p[MAXN];

int main () {
	// input
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> p[i];
	// starting points
	ans[0][0] = 1 - p[0]; // avali mishe element, dovomi mishe tedad
	ans[0][1] = p[0];
	// calculation
	for (int i = 1; i < n; i ++) // tossing each coin
		for (int j = 0; j <= i + 1; j ++) { // in wich line it will endup
			ans[i][j] += (1 - p[i]) * ans[i - 1][j];
			if (j > 0)
				ans[i][j] += p[i] * ans[i - 1][j - 1];
		}
	int start = n / 2 + 1;
	double answer = 0;
	for (int i = start; i <= n; i ++)
		answer += ans[n - 1][i];
	if (n >= 5) {
		cout << setprecision(10) << fixed << answer << endl;
		return 0;
	}
	cout << answer << endl;
	return 0; 
}
