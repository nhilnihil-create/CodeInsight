#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

void b_bitter_alchemy(void) {
	int n,x;
	int m[100];
	int sum = 0;

	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> m[i];
		sum += m[i];
	}
	sort(m, m + n);
	
	int amari = x - sum;
	int hasu = amari / m[0];

	cout << n + hasu << endl;
}

int main()
{
	b_bitter_alchemy();
    return 0;
}