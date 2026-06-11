#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_some_sums(void) {
	int n, a, b;
	cin >> n >> a >> b;
	int sum = 0;
	int i_tmp;
	int i_sum = 0;
	for (int i = 1; i <= n; i++) {
		i_tmp = i;
		i_sum = 0;
		while (i_tmp>0) {
			i_sum += (i_tmp % 10);
			i_tmp /= 10;
		}
		if ((i_sum >= a) && (i_sum <= b)) {
			sum += i;
		}
	}
	cout << sum << endl;
}

int main()
{
	b_some_sums();
    return 0;
}