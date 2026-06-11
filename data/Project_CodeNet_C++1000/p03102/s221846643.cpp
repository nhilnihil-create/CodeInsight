#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

void b_can_you_solve_this(void) {
	int n, m, c;
	int* b;
	int a;
	int sum[20] = { 0 };
	int cnt = 0;
	cin >> n >> m >> c;
	b = (int*)calloc(m, sizeof(int));
	for (int i = 0; i < m; i++) cin >> b[i];
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			cin >> a;
			sum[j] += (a * b[i]);
		}
		sum[j] += c;
		if (sum[j] > 0) cnt++;
	}

	cout << cnt << endl;

	free(b);
}

int main()
{
    b_can_you_solve_this();

    return 0;
}
