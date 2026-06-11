#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
#define MAXX 100005
 
#define PI   3.14159265358979323846264338327950
 
#define F first
#define S second
 
#define ll 	 long long int
 
#define mod  1000000007



int main()
{
	FAST;
	string s;
	cin >> s;
	ll n = s.size();;
	ll a = 0, ab = 0, abc = 0, d = 1;
	for(ll i = 0; i < n; i ++){
		if(s[i] == 'A'){
			a += d;
		}
		else if(s[i] == 'B'){
			ab += a;
		}
		else if(s[i] == 'C'){
			abc += ab;
		}
		else{
			abc *= 3;
			abc += ab;
			ab *= 3;
			ab += a;
			a *= 3;
			a += d;
			d *= 3;
		}
		a %= mod;
		ab %= mod;
		abc %= mod;
		d    %= mod;
		
	}
	cout << abc;
	return 0;
}