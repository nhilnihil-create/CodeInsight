#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void c_3_or_2(void) {
	int n;
	cin >> n;
	vector<long long> a(n + 1);
	for (int i = 1; i <= n; i++)cin >> a[i];

	int oddcnt = 0;
	bool use_div2 = false;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		while (a[i] % 2 == 0) {
			a[i] /= 2;
			cnt++;
		}
	}
  cout << cnt << endl;
}

int main()
{
    c_3_or_2();
    return 0;
}