#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<tuple>
#include<bitset>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;

ll k[15];
ll p[15];
int main(void) {
	int n, m;
	cin >> n;
	cin >> m;
	vector<vector<ll>>s(m);
	for (int i = 0; i < m; i++) {
		cin >> k[i];
		s[i].resize(k[i]);
		for (int j = 0; j < k[i]; j++) {
			cin >> s[i][j];
			s[i][j]--;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> p[i];
	}
	ll ans = 0;
	for (int bit = 0; bit < (1 << n); bit++) {
		
		bool ok = true;
		for (int i = 0; i < m; i++) {
			ll count = 0;
			for (int j = 0; j < k[i]; j++) {
				if (bit & (1<<s[i][j])) {
					count++;
				}
			}
			if (p[i] % 2 != count % 2) {
				ok = false;
				break;
			}
			
		}
		
		
		if (ok) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
