#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

void b_maximum_difference(void) {
	int n;
	int a[100];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	
	sort(a, a + n);
	cout << abs(a[0] - a[n - 1]) << endl;
	
}

int main()
{
	b_maximum_difference();
    return 0;
}