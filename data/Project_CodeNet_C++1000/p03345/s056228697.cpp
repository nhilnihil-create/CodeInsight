#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	ll a, b, c, k; cin >> a >> b >> c >> k; k %= 2;
	ll sum = (a + b + c)/ 2;

	cout << (k ? (sum - a) - (sum - b) : (a - b)) << endl;
}