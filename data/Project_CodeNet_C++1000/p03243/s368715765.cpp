#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

#define MAXX 500005

#define PI 3.14159265358979323846264338327950

#define F first
#define S second

#define ll  int

#define mod  1000000007



int main()
{
	FAST;
	ll n;
	cin >> n;
	ll a = n/100;
 	ll c = n % 10;
 	ll b = n/ 10   % 10;
 	
	if(a >= c && b <= a){
		cout << a << a << a;
		return 0;
	}
	a ++;
	cout <<a << a << a;
	return 0;
}