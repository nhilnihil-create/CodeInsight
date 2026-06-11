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
	string s;
	cin >> s;
	ll n;
	cin >> n;
	for(ll i = 0; i < s.size(); i ++){
		if(s[i] == '1'){
			n--;
		}
		else{
			n = 0;
		}
		if(n == 0){
			cout << s[i]; return 0;
		}
	}

	return 0;
}