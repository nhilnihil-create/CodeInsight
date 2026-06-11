#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
#include <math.h>

using namespace std;

int N, A, B, C;
int Li[8];

int magic(int i, int a, int b, int c, int x, int y, int z, int v)
{
	int ans = INT_MAX;
	if (i == N)
	{
		if (x == 0 || y == 0 || z == 0)
			ans = INT_MAX;
		else
			ans = abs(a - A) + abs(b - B) + abs(c - C) + (x + y + z - 3) * 10;
		return ans;
	}
	ans = min(ans, magic(i + 1, a + Li[i], b, c, x + 1, y, z, v));
	ans = min(ans, magic(i + 1, a, b + Li[i], c, x, y + 1, z, v));
	ans = min(ans, magic(i + 1, a, b, c + Li[i], x, y, z + 1, v));
	ans = min(ans, magic(i + 1, a, b, c, x, y, z, v + 1));
	return ans;
}

void func()
{
	cin >> N >> A >> B >> C;

	for (int i = 0; i < N; ++i)
	{
		cin>>Li[i];
	}

	cout << magic(0,0,0,0,0,0,0,0) << endl;

	return;
}

int main() {

//	while (1)
		func();
	return 0;
}
