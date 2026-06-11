#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void c_special_trains(void) {
	int n;
	cin >> n;
	vector<int> c(n);
	vector<int> s(n);
	vector<int> f(n);
	for (int i = 1; i <= n - 1; i++) {
		cin >> c[i] >> s[i] >> f[i];
	}

	for (int i = 1; i <= n - 1; i++) {
		int total = 0;
		total += (s[i]+c[i]);
		for (int j = i + 1; j <= n-1; j++) {
			int wait_time;
			if (total < s[j]) wait_time = s[j] - total;
			else if (total % f[j] == 0) wait_time = 0;
			else wait_time = f[j] - total % f[j];

			total += (wait_time + c[j]);
		}
		cout << total << endl;
	}
	cout << "0" << endl;
}

int main()
{
    c_special_trains();
    return 0;
}