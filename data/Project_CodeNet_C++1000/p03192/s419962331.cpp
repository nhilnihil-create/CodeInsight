#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
#define MAXX 10005
 
#define PI   3.14159265358979323846264338327950

#define PB push_back 
#define F first
#define S second
 
#define ll 	 long long int

#define mod  1000000007

vector<ll> v[MAXX];

int main()
{
	FAST;
	string s;
	ll ans = 0;
	cin >> s;
	for(ll i = 0; i < s.size(); i ++){
		if(s[i] == '2'){
			ans ++;
		}
	}
	cout << ans;
	return 0;
}