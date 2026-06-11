#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
#define MAXX 10005
 
#define PI   3.14159265358979323846264338327950
 
#define F first
#define S second
 
#define ll 	 long long int
 
#define mod  1000000007



int main()
{
	FAST;
	ll a, b, c;
	cin >> a >> b >> c;
	ll x = abs(a - b), y = abs(a - c), z = abs(b - c);
	cout << min(x + y, min(y+z, x + z));
	return 0;
}