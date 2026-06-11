#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


int main()
{
	int64_t a,b,c,k;
	cin >> a >> b >> c >> k;

	int64_t minus = a - b;
	if (minus > 1000000000000000000 || minus < -1000000000000000000)
		cout << "Unfair" << endl;
	else if (k % 2 == 0)
		cout << minus << endl;
	else
		cout << -minus << endl;
}