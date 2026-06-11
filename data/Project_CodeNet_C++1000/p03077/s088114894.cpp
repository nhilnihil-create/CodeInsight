#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	ll n, a, b, c, d, e;
	cin>>n>>a>>b>>c>>d>>e;
	ll m = min({a, b, c, d, e});
	cout<<(n + m - 1)/m + 4<<endl;

	return 0;
}