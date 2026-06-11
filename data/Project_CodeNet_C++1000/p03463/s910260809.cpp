#include <iostream>
#include <unordered_set>
#include <cstdint>
#include <vector>
#include <sstream>
#include <string>
#include <climits>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <map>
using namespace std;

int main()
{
	int n;
	int a, b;
	cin >> n >> a >> b;

	if (n == 2 || a + 1 == b)
	{
		cout << "Borys";
		return 0;
	}

	while (1)
	{
		a++;
		if (a == b - 1)
		{
			cout << "Alice";
			return 0;
		}
		b--;
		if (b == a + 1)
		{
			cout << "Borys";
			return 0;
		}
	}
}