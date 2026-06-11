
#include <iostream>
#include <algorithm>
#include "math.h"


using namespace std;

int main()
{
	int a[4] = {};
	int x[6];
	for (int i = 0; i < 6; i++) {
		cin >> x[i];
	}
	
	for (int i = 0; i < 6; i++) {
		a[x[i] - 1]++;
		if (a[x[i] - 1] == 3) {
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;
	return 0;
}