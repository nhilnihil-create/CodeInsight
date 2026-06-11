#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_stone_monument(void) {
	int a, b;
	cin >> a >> b;

	int diff = b - a;
	int sum = 0;
	for (int i = 1; i <= diff; i++) sum += i;

	cout << sum - b << endl;
}

int main()
{
	b_stone_monument();
    return 0;
}