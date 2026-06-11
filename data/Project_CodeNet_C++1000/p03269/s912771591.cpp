#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int l, n, s;
vector<int> a1, a2, a3;
int main()
{
	int i, j;
	cin >> l;
	for (i = 1, j = 1; i * 2 <= l; i *= 2, j++) {
		a1.push_back(j), a2.push_back(j + 1), a3.push_back(0);
		a1.push_back(j), a2.push_back(j + 1), a3.push_back(i);
	}
	n = j;
	s = i;
	cout << n << ' ';
	l -= i;
	for (j--; j >= 0; j--) {
		if (l & (1 << j)) {
			a1.push_back(j + 1), a2.push_back(n), a3.push_back(s);
			s += 1 << j;
		}
	}
    cout << a1.size() << endl;
    for (i = 0; i < a1.size(); i++) {
		printf("%d %d %d\n", a1[i], a2[i], a3[i]);
    }
    return 0;
}