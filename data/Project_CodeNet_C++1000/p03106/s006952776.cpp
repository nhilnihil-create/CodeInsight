#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

void b_k_th_common_divisor(void) {
	int a, b, k;
	cin >> a >> b >> k;
	int ptr = 0;
	int* div;
	div = (int*)calloc(100, sizeof(int));
	for (int i = 1; i <= 100; i++) {
		if (i > a && i > b)break;
		if ((a % i == 0) && (b % i == 0)) {
			div[ptr++] = i;
			
		}
	}

	sort(div, div + 100, greater<int>());

	cout << div[k - 1] << endl;
}

int main()
{
    b_k_th_common_divisor();

    return 0;
}