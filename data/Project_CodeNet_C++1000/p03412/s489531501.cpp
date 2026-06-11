#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0)
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ALL(x) (x).begin(), (x).end()
#define dump(x) cout << (x) << endl
#define LMAX 9223372036854775807LL
#define LMIN -9223372036854775807LL
using ll = long long;
template<typename T>
using vec = vector<T>;
using P = pair<ll, ll>;
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
	fill((T *)array, (T *)(array + N), val);
}

const ll INF = 1e16;
const ll MOD = 1e9 + 7;
//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//ll pas[51][52];



signed main(){
	IOS;
	ll n;
	cin >> n;
	vec<ll> a(n),b(n),am(n),bm(n);
	REP(i,n)cin >> a[i];
	REP(i,n)cin >> b[i];
	ll ans = 0;
	for(ll i = 0;i < 30;i++){
		ll mod = (1ll << i + 1);
		REP(j, n)am[j] = a[j] % mod;
		REP(j, n)bm[j] = b[j] % mod;
		sort(ALL(bm));
		ll cnt = 0;
		ll t = (1ll << i);
		REP(j, n){
			cnt += lower_bound(ALL(bm),2 * t - am[j]) - lower_bound(ALL(bm),t - am[j]);
			cnt += lower_bound(ALL(bm),4 * t - am[j]) - lower_bound(ALL(bm),3 * t - am[j]);
		}
		if(cnt % 2)ans += (1ll << i);
	}
	dump(ans);
}