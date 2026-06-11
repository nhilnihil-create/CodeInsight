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
	ll n;
	cin >> n;
	if(n < 1200){
		cout << "ABC";
		return 0;
	}
	if(n < 2800){
		cout << "ARC";
		return 0;
	}
	cout << "AGC";
	return 0;
}