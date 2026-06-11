#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

void b_christmas_eve_eve(void) {
	int n;
	int* p;
	cin >> n;
	p = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) cin >> p[i];

	sort(p, p + n, std::greater<int>());
	p[0] /= 2;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += p[i];
	}
	cout << sum << endl;
}
int main()
{
    b_christmas_eve_eve();

    return 0;
}
