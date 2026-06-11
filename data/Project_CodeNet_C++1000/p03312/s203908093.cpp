//Forever... Check size - Reading order - Use scanf - Clear structures
#pragma GCC optimize ("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define sz(x) int(x.size())
#define pb push_back
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ff first
#define ss second
#define REP(i,a,b) for(int i = int(a); i < int(b); ++ i)
typedef long long ll;
typedef pair<int, int> ii;

const int N = 2e5 + 2;

int l[N], r[N];
vector<ll> vec, psum;

ll getsum(int l, int r){
	ll res = psum[r - 1];
	if(l) res -= psum[l - 1];
	return res;
}

int main(){
	fastio;
	int n; cin >> n;
	vec.resize(n); psum.resize(n);
	ll sum = 0;
	REP(i,0,n){
		cin >> vec[i];
		psum[i] += vec[i];
		if(i) psum[i] += psum[i-1];
	}
	int ptr = 1;
	REP(i,2,n){
		while(ptr + 1 < i && llabs(getsum(0,ptr) - getsum(ptr, i)) > llabs(getsum(0,ptr+1) - getsum(ptr+1,i))) ptr ++;
		l[i] = ptr;
	}
	ptr = n - 1;
	for(int i = n - 2; i >= 0; -- i){
		while(ptr - 1 > i && llabs(getsum(i,ptr) - getsum(ptr,n)) > llabs(getsum(i,ptr-1) - getsum(ptr-1,n))) ptr --;
		r[i] = ptr;
	}
	ll ans = 1e18;
	REP(i,2,n-1){
		int x = l[i], y = i, z = r[i];
		ll b = getsum(0, x), c = getsum(x, y), d = getsum(y, z), e = getsum(z, n);
		ll low = min(b, min(c, min(d, e)));
		ll high = max(b, max(c, max(d, e)));
		ans = min(ans, high - low);
	}
	cout << ans << endl;
	return 0;
}
