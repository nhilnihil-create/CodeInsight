#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_toll_gates(void) {
	int n, m, x;
	int a[110] = { 0 };
	cin >> n >> m >> x;
	int aa;
	for (int i = 1; i <= m; i++) {
		cin >> aa;
		a[aa]++;
	}

	int cost_l = 0, cost_r = 0;

	for (int i = x; i >= 0; i--) {
		cost_l += a[i];
	}
	for (int i = x; i <= n; i++) {
		cost_r += a[i];
	}

	int min = cost_l;
	if (min > cost_r) {
		min = cost_r;
	}
	cout << min << endl;

}

int main()
{
	b_toll_gates();
    return 0;
}