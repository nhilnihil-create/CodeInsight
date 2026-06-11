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

	int n; cin>>n;
	ll m, a, r, c, h;
	m = a = r = c = h = 0;
	for(int i = 0; i < n; i++){
		string s; cin>>s;
		if(s[0] == 'M')m++;
		if(s[0] == 'A')a++;
		if(s[0] == 'R')r++;
		if(s[0] == 'C')c++;
		if(s[0] == 'H')h++;
	}
	ll ans = m*a*r + m*a*c + m*a*h + m*r*c + m*r*h + m*c*h + a*r*c + a*r*h + a*c*h + r*c*h;
	cout<<ans<<endl;

	return 0;
}