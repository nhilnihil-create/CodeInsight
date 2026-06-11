#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
#define MAXX 10005
 
#define PI 3.14159265358979323846264338327950
 
#define F first
#define S second
 
#define ll 	 long long int
 
#define mod  1000000007

ll ss[MAXX];

int main()
{
	FAST;
	ll a, b;
    cin >> a >> b;
    ll x = a*b;
    x -= b;
    x -= (a-1);
    cout << x;
	return 0;
}