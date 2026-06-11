#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
 
#define MAXX 100005
 
#define PI 3.14159265358979323846264338327950
 
#define F first
#define S second
 
#define ll 	 long long int
 
#define mod  1000000007

map<string, int> m;




int main()
{
	FAST;
	ll a, b, c;
	cin >> a >> b >> c;
	if(a > b){
		swap(a, b);
	}
	if(c > a && b > c){
		cout << "Yes";
		return 0;
	}
	cout << "No";
	return 0;
}