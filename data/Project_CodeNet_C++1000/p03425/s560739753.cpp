#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N;
	cin >> N;
	int v[5] = {0,0,0,0,0};
	rep(i,N) {
		string s;
		cin >> s;
		if (s[0] == 'M') v[0]++;
		else if (s[0] == 'A') v[1]++;
		else if (s[0] == 'R') v[2]++;
		else if (s[0] == 'C') v[3]++;
		else if (s[0] == 'H') v[4]++;
	}

	ll ans = 0;
	rep(i,32) {
		ll k = 1;	
		int c = 0;
		rep(j,5) {
			if (i>>j & 1) {
				c++;
				k *= v[j];
			}
		}
		if (c == 3) ans += k;
	}
	cout << ans << endl;
	return 0;
}
