#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, a, b;
	cin >> n >> a >> b;

	printf("%d %d\n", min(a, b), max(a + b - n, 0));
	
	return 0;
}