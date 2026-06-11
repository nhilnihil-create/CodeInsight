#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int x = c - a;
	int y = d - b;
	printf("%d %d %d %d\n", c-y, d+x, a-y, b+x);
	return 0;
}
