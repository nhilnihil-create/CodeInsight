#include <iostream>
#include <cstdio>
#define N 30000
using namespace std;

int n;
int main()
{
	int i;
	cin >> n;
	if (n == 3) {cout << "2 5 63"; return 0;}
	cout << "2 4 3 9 ";
	n -= 4;
	for (i = 6; n >= 3 && i + 4 <= N; i += 6, n -= 3) printf("%d %d %d ", i, i + 2, i + 4);
	if (n % 2) n--, printf("%d ", i);
	for (i = 15; n; i += 12, n -= 2) printf("%d %d ", i, i + 6);
    return 0;
}