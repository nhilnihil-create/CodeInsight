#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)

int main()
{
	string S; cin >> S;
	ll a, b, c, d;
	a = S[0] - '0';
	b = S[1] - '0';
	c = S[2] - '0';
	d = S[3] - '0';
	//cout << a << " " << b << " " << c << " " << d << endl;

	ll index = 0;
	string ans = "";
	rep(i, (1<<3)) {
		ll tmp = S[0] - '0';
		ans = S[0];
		index = 1;
		rep (j, 3) {
			if ((i >> j) & 0x01) {
				tmp += S[index] - '0';
				ans += '+'; ans += S[index];
			}
			else {
				tmp -= S[index] - '0';
				ans += '-'; ans += S[index];
			}
			index++;
		}
		if (tmp == 7) {
			ans += "=7";
			cout << ans << endl;
			exit(0); 
		}

	}
	


}
