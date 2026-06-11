#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	ll n;
	cin >> n;
	ll m = 0, a = 0, r = 0, c = 0, h = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s[0] == 'M')
			m++;
		if (s[0] == 'A')
			a++;
		if (s[0] == 'R')
			r++;
		if (s[0] == 'C')
			c++;
		if (s[0] == 'H')
			h++;
	}
	ll ans = 0;
	ll d[5];
	d[0] = m;
	d[1] = a;
	d[2] = r;
	d[3] = c;
	d[4] = h;
	for (int  i = 0 ; i < 5 ; i++){
		for (int j = i+1 ; j < 5 ; j++){
			for (int k = j+1 ; k < 5 ; k++){
				ans += d[i]*d[j]*d[k];
			}
		}
	}
	cout << ans << endl;
}
