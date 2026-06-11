#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

void b_palace(void) {
	int n, t, a;
	int h[10000];
	cin >> n;
	cin >> t >> a;
	for (int i = 0; i < n; i++) cin >> h[i];

	// h[i] = (t-a)/0.006
	double diff = (t - a) / 0.006;
	double diff_min = 100000.000;
	int min_index = 0;
	for (int i = 0; i < n; i++) {
		double diff_tmp = abs(h[i] - diff);
		if (diff_tmp < diff_min) {
			diff_min = diff_tmp;
			min_index = i;
		}
	}
	cout << min_index + 1 << endl;

}

int main()
{
	b_palace();
    return 0;
}