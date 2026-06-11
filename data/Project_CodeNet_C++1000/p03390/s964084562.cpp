#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;
const ll inf = 1e10;


// 1 2 3 4   5 6 7
// A i B C x D E F
// F E D C B y i A
// 1 2 3 4 5 6 7 8

ll solve(ll x, ll y) {



    // Obviously we should assign smallest numbers to larger numbers to minimize product.
    // ABCDEFGH
    // HGFEDCBA
    
    // The maximal product value will be somewhere in the middle, so we wiggle around [cnt/2-10,cnt/2+10]
    // If we come after x, then our ranking for contest 1 will get boosted by 1.
    // And then because smaller are paired with bigger, we reverse this logic to see if our ranking
    // for contest 2 also gets boosted.
    

    function<bool(ll)> ok = [&](ll cnt) {
	ll mx = 0;
	for (ll i=max(1ll, cnt/2 - 10); i<= min(cnt, cnt/2 + 10); i++) {
	    ll lo = i;
	    if (lo >= x) lo++;
	    ll hi = cnt-i+1;
	    if (i <= cnt-y+1) hi++;
	    mx = max(mx, lo*hi);		
	}
	return mx < x*y;
    };


    
    ll lo = 0;
    ll hi = inf;
    while (hi-lo>1) {
	ll mid = (hi+lo)/2;
	if (ok(mid)) {
	    lo = mid;
	} else {
	    hi = mid;
	}
    }

    return lo;
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    int t; cin>>t;
    while (t--) {
	ll a,b;
	cin>>a>>b;
	cout<<solve(a,b)<<"\n";
    }
    
    
    return 0;
}
