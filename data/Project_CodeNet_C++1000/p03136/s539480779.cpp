#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

void b_polygon(void) {
	int n;
	cin >> n;
	int* l;
	l = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)cin >> l[i];

	sort(l, l + n, greater<int>());

	int sum = 0;
	for (int i = 1; i < n; i++) sum += l[i];

	if (l[0] < sum) cout << "Yes" << endl;
	else            cout << "No" << endl;
}

int main()
{
    b_polygon();

    return 0;
}