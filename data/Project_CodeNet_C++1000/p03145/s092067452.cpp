#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define MAXX 500005
#define PI 3.14159265358979323846264338327950
#define F first
#define S second
#define ll   int
#define mod  1000000007



int main()
{
	FAST;
	ll a[5];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	cout << (a[0] * a[1]) / 2;
}