#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
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
	ll a, b, x;
	cin >> a >> b >> x;
	if(a <= x && x - a <= b){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}