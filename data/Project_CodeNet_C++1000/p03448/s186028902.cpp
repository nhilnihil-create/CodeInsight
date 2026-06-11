#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_coins(void) {
	int a, b, c,x;
	cin >> a >> b >> c>>x;

	int cnt = 0;
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			int k = x - 500 * i - 100 * j;
			if (k < 0) break;
			if (k % 50 == 0) {
				if (k / 50 <= c) cnt++;
			}
		}
	}

	cout << cnt << endl;

}

int main()
{
	b_coins();
    return 0;
}