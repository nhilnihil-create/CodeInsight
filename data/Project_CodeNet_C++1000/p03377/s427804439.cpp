// ABC_094_A
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define forn(i, n) for(int i = 0; i < (int)n; ++i)

int main()
{
	int a, b, x;
	cin >> a >> b >> x;

	if(a <= x && a+b >= x) cout << "YES" << "\n"; 
	else cout << "NO" << "\n";

	return 0;
}