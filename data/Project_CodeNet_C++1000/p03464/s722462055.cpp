#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
 
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

ll mod = 1e9+7;

//edutorial の解法を実装して二分探索を復習

//f_p(x) := x - x % p
//g(x) := f_a[1](f_a[2](...(f_a[n](x))))

//答えは g(n) == 2 なる n の最小値と最大値
//f : 単調 より g : 単調なので二分探索が有効

//check : 条件を満たすか確認するやつ
bool check(ll x, vll &a, ll type){
	for(auto q : a){
		x -= x % q;
	}
	if(type == 1){
		if(x >= 2) return true;
		else return false;
	}
	else{
		if(x <= 2) return true;
		else return false;
	}
}

//1つめ : g(n) >= 2 となる最小の n を二分探索
ll search_min(vll &a){
	ll ng = 0;
	ll ok = 1e18;

    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid, a, 1)) ok = mid;
        else ng = mid;
    }
    return ok;
}

//2つめ : g(n) <= 2 となる最大の n を二分探索
ll search_max(vll &a){
	ll ng = 1e18;
	ll ok = 0;

    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid, a, 2)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

	ll k;
	cin >> k;
	vll a(k);
	REP(i, k) cin >> a[i];

	ll mi = search_min(a);
	ll ma = search_max(a);

	if(mi > ma){
		cout << -1 << endl;
		return 0;
	}

	cout << mi << " " << ma << endl;
    return 0;
}