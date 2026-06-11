#include <iostream>
#include <cstdio>
using namespace std;
 
int n, a[9]{3, 9, 2, 4, 8, 10, 6, 12};
int main()
{
	int i;
	cin >> n;
	if (n == 3) {cout << "2 5 63"; return 0;}
	if (n % 2) n--, cout << "30000 ";
	for (i = 0; i < n; i++) printf("%d ", a[i % 8] + i / 8 * 12);
    return 0;
}