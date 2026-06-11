#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

void b_five_dishes(void) {
	int t[5];
	int max_index = 0;
	int max_remain = 0;
	int min_time = 0;
	for (int i = 0; i < 5; i++) {
		cin >> t[i];
		if (t[i] % 10 != 0) {
			int remain = 10 - (t[i] % 10);
			if (remain >= max_remain) {
				max_remain = remain;
				max_index = i;
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		if (i == max_index)continue;
		
		min_time += t[i];
		if (t[i] % 10 != 0) {
			int remain = 10 - (t[i] % 10);
			min_time += remain;
		}
	}
	min_time += t[max_index];

	cout << min_time << endl;
}
int main()
{
    b_five_dishes();

    return 0;
}
