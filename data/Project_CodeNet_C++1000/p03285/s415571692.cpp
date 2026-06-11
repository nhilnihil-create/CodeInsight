#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
#define MAXX 10005
 
#define PI 3.14159265358979323846264338327950
 
#define F first
#define S second
 
#define ll 	 long long int
 
#define mod  1000000007



int main()
{
	FAST;
	ll n;
	cin >> n;
	if(n % 4 == 0 || n % 7 == 0){
		cout << "Yes";
		return 0;
	}
	ll a = n;
	while(a > 0){
		a -= 4;
		if(a % 7 == 0){
			cout << "Yes";
			return 0;
		}
	}
	while(n > 0){
		n -= 7;
		if(a % 4 == 0){
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;
}