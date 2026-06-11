#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c;
	cin >> a >> b >> c;
	string k = "No";
	if(max(a,b) >= c && min(a,b) <= c)
	{
		k = "Yes";
	}
	cout << k << endl;
	return 0;
}
