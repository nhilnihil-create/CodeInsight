#include <bits/stdc++.h>
#define bp(x) __builtin_popcountll(x)
#define ll int64_t
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define fw(i, l, r, c) for(int i = l; i <= r; i += c)
#define bw(i, r, l, c) for(int i = r; i >= l; i -= c)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
const int mod = 1e9 + 7, inf = 1061109567;
const long long infll = 4557430888798830399;

ll n, k;
ll a[1001];
vi sum;

signed main() {
	//freopen("blu.inp", "r", stdin);
	//freopen("blu.out", "w", stdout);
	//fastio;
	cin >> n >> k;
	fw(i, 0, n - 1, 1){
		cin >> a[i];	
	}
	fw(i, 0, n - 1, 1){
		ll summ = 0;
		fw(j, i, n - 1, 1){
			summ += a[j];
			sum.pb(summ);
		}
	}
	sum.pb(a[n - 1]);
	ll res = 0;
	vi num;
	bw(i, 50, 0, 1){
		fw(j, 0, sum.size() - 1, 1){
			ll check = (sum[j] >> i) & 1;
			if(check){
				num.pb(sum[j]);
			} 
		}
		if(num.size() >= k){
			sum.clear();
			fw(j, 0, num.size() - 1, 1){
				sum.pb(num[j]);
			}
		}
		num.clear();
	}
	ll ans = LLONG_MAX;
	for(int i = 0; i < sum.size(); i++) {
		ans &= sum[i];
	}
	cout << ans;
	return 0;
}
