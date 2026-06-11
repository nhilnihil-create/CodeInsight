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
	string s1, s2;
	cin >> s1 >> s2 ; ll x = 0;
	for(ll i = 0; i < s1.size(); i++){
		if(s1 == s2){
			cout << "Yes";
			return 0;
		}
		s1 += s1[0];
		s1.erase(s1.begin());
	}
	cout << "No";
	return 0;
}