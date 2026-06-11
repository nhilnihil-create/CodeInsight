#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;


void b_time_limit_exceeded(void) {
	int N,T;
	int* c;
	int* t;
	bool detect = false;
	cin >> N>>T;
	c = (int*)calloc(N, sizeof(int));
	t = (int*)calloc(N, sizeof(int));
	for (int i = 0; i < N; i++) {
		cin >> c[i];
		cin >> t[i];
	}

	int min = c[0];

	for (int i = 0; i < N; i++) {
		if (t[i] > T) continue;

		if (min > c[i]) {
			min = c[i];
		}
		detect = true;
	}

	if (!detect) cout << "TLE" << endl;
	else         cout << min << endl;

}

int main()
{
    b_time_limit_exceeded();
}