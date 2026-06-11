#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

#define MAXX 500005
#define PI 3.14159265358979323846264338327950
#define F first
#define S second
#define ll  long long int
#define mod  1000000007



int main()
{
	FAST;
	ll n;
	double a, b;
	cin >> n >> a >> b ;
	double mn = a;
	vector< pair <double , int> > v; 
	for(ll i = 1; i <= n; i ++){
		double f;
		cin >> f;
		double x = a - (f * 0.006);
		x = abs(b - x);
		v.push_back( {x, i} );
	}
	sort(v.begin(), v.end());
	cout << v[0].second;
	
}