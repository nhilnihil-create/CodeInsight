#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

void b_foods_loved_by_everyone(void) {
	int n, m,k;
	int* food;
	cin >> n >> m;
	food = (int*)calloc(m, sizeof(int));

	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			food[x-1]++;
		}
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		if (food[i] == n) cnt++;
	}

	cout << cnt << endl;
}

int main()
{
    b_foods_loved_by_everyone();

    return 0;
}