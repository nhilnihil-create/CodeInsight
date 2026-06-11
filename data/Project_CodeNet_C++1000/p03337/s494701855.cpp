#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

const int MOD = 1000000007;
int main()
{
	int a, b;
	cin >> a >> b ;
	int s = max(a+b,max(a-b,a*b));
	cout << s << endl;
	return 0;
}