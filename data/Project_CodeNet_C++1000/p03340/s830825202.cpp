
#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;

const ll MOD_CONST = 1000000007;



int main()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<ll> s(n+1);
	for (int i = 0; i < n; i++) {
		s[i + 1] = s[i] + a[i];
	}
	vector<ll> x(n + 1);
	x[0] = (1 << 21) - 1;
	for (int i = 0; i < n; i++) {
		x[i + 1] = x[i] ^ a[i];
	}

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		if ((s[n] - s[i]) ==( x[n] ^x[i])) {
			ans += n - i;
		}
		else {
			int l = i+1;
			int r = n;
			int mid = (l + r) / 2;
			while (l != mid) {
				
				if ((s[mid] - s[i]) ==( x[mid] ^x[i])) {
					l = mid;
				}
				else {
					r = mid;
				}
				mid = (l + r) / 2;
			}
			//cout << l -i<< endl;
			ans += l - i;
		}
		//cout << ans << endl;
	}

	cout << ans << endl;
}  

