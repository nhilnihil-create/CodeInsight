#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_kagami_mochi(void) {
	int n;
	int d[110];
	cin >> n;

	for (int i = 0; i < n; i++)cin >> d[i];

	sort(d, d + n);


	int cnt = 1;
	for (int i = n-2; i >=0 ; i--) {
		if (d[i] != d[i + 1]) cnt++;
	}

	cout << cnt << endl;

}

int main()
{
	b_kagami_mochi();
    return 0;
}