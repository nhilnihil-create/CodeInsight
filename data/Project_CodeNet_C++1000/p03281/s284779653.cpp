#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_105(void) {
	int n;
	cin >> n;

	int cnt = 0;

	for (int i = 1; i <= n; i+=2) {
		int div_cnt = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) div_cnt++;
		}
		if (div_cnt == 8)cnt++;
	}

	cout << cnt << endl;
}

int main()
{
	b_105();
    return 0;
}