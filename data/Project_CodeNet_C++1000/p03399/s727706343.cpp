#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <math.h>
typedef long long ll;
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int x, y;
	if (a < b) x = a; else x = b;
	if (c < d) y = c; else y = d;
	cout << x + y;
}