#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <bitset>

using namespace std;

int n;
const int N = 2001;

int a[N];

bitset<N * N> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	s[0] = 1;
	for (int i = 0; i < n; i++) s = s | (s << a[i]);
	int x = 0;
	for (int i = 0; i < n; i++) x += a[i];
	if (s.count() % 2 == 1)
    {
        cout << x / 2;
        return 0;
    }
    for (int i = (x + 1) / 2; i <= x; i++) if (s[i])
    {
        cout << i;
        return 0;
    }
}
