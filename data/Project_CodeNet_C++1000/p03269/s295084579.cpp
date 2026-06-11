#include <iostream>
#include <cstdio>
using namespace std;

int n, k, sz, cnt, a[25];
int main()
{
	int i, j;
	cin >> n;
	for (k = 1, sz = 0; k <= n; k *= 2, sz++);
	k /= 2;
	sz--;
	i = 1;
	cnt = sz * 2;
	while (n > 1) {
		if (n % 2) {a[i] = 1; cnt++;}
		i++;
		n /= 2;
	}
	cout << sz + 1 << " " << cnt << endl;
	for (i = 1, j = 1; i <= sz; i++, j *= 2) {
		printf("%d %d 0\n", i, i + 1);
		printf("%d %d %d\n", i, i + 1, j);
		if (a[i] == 1) {
			printf("%d %d %d\n", i, sz + 1, k);
			k += j;
		}
	}
    return 0;
}
