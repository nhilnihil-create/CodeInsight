#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void a_candy_distribution_again(void) {
	int n, x;
	int a[100];
	int cnt = 0;
	cin >> n >> x;
	for (int i = 0; i < n; i++)cin >> a[i];

	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (i == n - 1){
			cnt = (x==a[i])?cnt+1:cnt;
		}
		else {
			cnt = (x >= a[i]) ? cnt + 1 : cnt;
		}
		x -= a[i];
		if (x <= 0)break;
	}
	cout << cnt << endl;
}

int main()
{
	a_candy_distribution_again();
    return 0;
}