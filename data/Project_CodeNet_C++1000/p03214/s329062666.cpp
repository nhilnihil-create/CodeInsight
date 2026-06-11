#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n, 0);
	float total = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		total += a[i];
	}

	total /= n;
	int best = 0;
	for (int i = 1; i < n; i++)
		if (abs(a[i] - total) < abs(total - a[best]))
			best = i;
	printf("%d", best);
	return 0;
}
