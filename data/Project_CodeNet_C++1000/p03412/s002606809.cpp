#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2
#define all(x) (x).begin(),(x).end()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define debug_vec(v) cerr<<#v<<":";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
using namespace std;

// int MOD = 998244353;
int MOD = 1000000007;


signed main(){
	
	ll n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> b(n);
	vector<ll> c(n);

	rep(i,n)cin >> a[i];
	rep(i,n)cin >> b[i];

	int cnt[30] = {0};
	ll mask = 0;
	rep(bit,29){
		mask = (mask<<1)+1;
		rep(i,n)c[i] = b[i]&mask;
		SORT(c);
		rep(ai,n){
			ll fa = a[ai]&mask;
			ll x = 1LL<<bit;
			auto r1 = lower_bound(c.begin(),c.end(),x-fa);
			auto r2 = lower_bound(c.begin(),c.end(),2*x-fa);
			auto r3 = lower_bound(c.begin(),c.end(),x+2*x-fa);
			auto r4 = lower_bound(c.begin(),c.end(),4*x-fa);
			cnt[bit] += (ll)(r2-r1) + (ll)(r4-r3); 
		}
	}

	ll ans = 0;
	rep(i,29){
		ans += (1LL<<i)*(cnt[i]%2);
	}

	cout << ans << endl;


	return 0;
}

// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://cf16-exhibition-final-open.contest.atcoder.jp/tasks/cf16_exhibition_final_a
// rm -r -f test;oj dl https://cf17-final-open.contest.atcoder.jp/tasks/cf17_final_a
// rm -r -f test;oj dl http://arc092.contest.atcoder.jp/tasks/arc092_b