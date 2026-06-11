#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

typedef long long ll;

ll T,A,B,C,D;

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> A >> B >> C >> D;
		if (A < B || D < B)
		{
			puts("No");
			continue;
		}
		ll g = __gcd(B,D);
		if (B / g > (C - A % g) / g + 1 || C < A % g)
		{
			puts("No");
			continue;
		}
		puts("Yes");
	}
	return 0;
} 