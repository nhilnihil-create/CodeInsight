#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
#define MAXX 100005
 
#define PI   3.14159265358979323846264338327950

#define PB push_back 
#define F first
#define S second
 
#define ll 	 long long int

#define mod  1000000007




int main()
{
	FAST;
	ll a, b;
	cin >> a >> b;
	if(a % 2 == 0 || b % 2 == 0){
		cout << "Even";
		return 0;
	}
	cout << "Odd";
	return 0;
}