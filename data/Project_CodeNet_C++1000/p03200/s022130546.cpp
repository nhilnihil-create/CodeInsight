#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl            "\n"
#define sq(x)           ((x)*(x))
#define pi              acos(-1.0)
#define NUM             1000005

typedef long long ll;


int main()
{
    FastRead

    ll x = 0,ans = 0;
    string s;

	cin >> s;

	for (ll i = 0; i < s.size(); i++) {

		if (s[i] == 'W') {
			ans += x;
		}
		else {
			x++;

		}
	}
	cout << ans << endl;

	return 0;
}
