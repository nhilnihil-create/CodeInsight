#define _USE_MATH_DEFINES 1
#define _EXT_CODECVT_SPECIALIZATIONS_H 1
#define _EXT_ENC_FILEBUF_H 1
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define MOD 1000000007ll
#define EPS 1e-9

#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock

typedef long long         ll;
typedef long double       ld;
typedef pair <ll,ll>      pl;
typedef tuple <ll,ll,ll>  tl;

ll X, Y, Z, K, A[1005], B[1005], C[1005];
vector <ll> sel, ans;
std::priority_queue < ll, vector<ll>, greater<ll> > pq;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> X >> Y >> Z >> K;
	for (ll i = 0; i < X; i++) cin >> A[i];
	for (ll j = 0; j < Y; j++) cin >> B[j];
	for (ll k = 0; k < Z; k++) cin >> C[k];
	
	for (ll i = 0; i < X; i++) {
		for (ll j = 0; j < Y; j++) {
			sel.push_back(A[i] + B[j]);
		}
	}
	
	sort(sel.begin(), sel.end(), greater<ll>());
	
	for (ll k = 0; k < Z; k++) {
		for (ll t = 0; t < min(K, (ll)sel.size()); t++) {
			ll tot = C[k] + sel[t];
			if ((ll)pq.size() < K) {
				pq.push(tot);
			} else if (tot > pq.top()) {
				pq.pop();
				pq.push(tot);
			} else break;
		}
	}
	
	while (!pq.empty()) {
		ans.push_back(pq.top());
		pq.pop();
	}
	
	for (ll t = K-1; t >= 0; t--) {
		cout << ans[t] << '\n';
	}
	
    return 0;
}