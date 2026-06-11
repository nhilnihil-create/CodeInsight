#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
#define MAXX 200010
 
#define PI   3.14159265358979323846264338327950
 
#define PB push_back 
#define F first
#define S second
 
#define ll 	long long int
 
#define mod  1000000007
 
 
 
int main()
{
	FAST;
	ll n, m;
	cin >> n >> m;
	ll ans = 0;
	if(n >= 2){
		n -= 2;
	}
	if(m >= 2){
		m -= 2;
	}
	ans = n*m;
	
	cout <<  ans;
	return 0;
}