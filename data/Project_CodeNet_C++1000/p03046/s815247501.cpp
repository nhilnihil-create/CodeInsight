#include <iostream>
#include <cstdio>
using namespace std;

int n, m, s;
int main()
{
	int i;
	cin >> n >> m;
	for (s = 1, i = 0; i < n; s *= 2, i++);
	s--;
	if (s < m || n == 1 && m == 1) {
		cout << -1;
		return 0;
	}
	if (n == 1 && m == 0) {
		cout << "0 1 1 0";
		return 0;
	}
	cout << m << " ";
    for (i = 0; i <= s; i++) {
		if (i == m) continue;
		printf("%d ", i);
    }
    cout << m << " ";
    for (i = s; i >= 0; i--) {
		if (i != m) printf("%d ", i);
    }
    return 0;
}
