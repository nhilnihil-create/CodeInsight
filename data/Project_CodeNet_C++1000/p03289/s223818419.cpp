#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
#define MAXX 10005
 
#define PI   3.14159265358979323846264338327950
 
#define F first
#define S second
 
#define ll 	 long long int
 
#define mod  1000000007

map<char, int> m;
map<char, int> m1;
int main()
{
	FAST;
	string s;
	cin >> s;
	ll x = 0;
	for(ll i = 0; i < s.size(); i ++){
		if(s[i] >= 'A' && s[i] <= 'Z'){
			x++;
		}
		m[s[i]] ++;
		m1[s[i]] = i;
	}
	if(m['C'] == 1 && x == 2 && m1['C'] >= 2 && m1['C'] <= s.size() -2 && m1['A'] == 0 && m['A'] == 1){
		cout << "AC";
		return 0;
	} 
	cout << "WA";
	return 0;
}