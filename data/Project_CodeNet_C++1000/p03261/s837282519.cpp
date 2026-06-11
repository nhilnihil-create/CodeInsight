#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
#define MAXX 100005
 
#define PI 3.14159265358979323846264338327950
 
#define F first
#define S second
 
#define ll 	 int
 
#define mod  1000000007

map<string, int> m;

int main()
{
	FAST;
	ll n;
	cin >> n;
	string a[n+5];
	for(ll i = 0; i < n; i ++){
		cin >> a[i];
	}
	m[a[0]] = 1;
	for(ll i = 1; i < n; i ++){
		if(m[a[i]] == 1 || a[i][0] != a[i-1][a[i-1].size() - 1]){
			cout << "No";
			return 0;
		}
		else{
			m[a[i]] = 1;
		}
	}
	cout << "Yes";
	return 0;
}