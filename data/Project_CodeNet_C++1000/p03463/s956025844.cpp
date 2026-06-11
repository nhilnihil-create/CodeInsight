#include <bits/stdc++.h>
using namespace std;
long long n,a,b;
int main()
{
	cin >> n >> a >> b;
	if ((b - a) % 2 != 0) cout << "Borys\n";
		else cout << "Alice\n";	
	return 0;	
 } 