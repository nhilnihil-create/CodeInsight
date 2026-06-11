#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef double lld;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
typedef unordered_map<lli,unordered_map<lli,lli>> graph;
typedef complex<double> cmp;
typedef vector<cmp> vcl;

const lli e5 = 100009;

lli n;
lli a[e5];
lli b[e5];
unordered_map<lli,lli> m;
lli l;

class bit {
private:
	vll* v;
	lli n;
public:
	bit (lli n) {
		this->v = new vll(n+1);
		this->n = n;
	}
	void add(lli i,lli val){
		for(;i <= n;i += i&-i) this->v->at(i) += val;
	}
	lli sum(lli i){
		lli ret = 0;
		for(;i > 0;i -= i&-i) ret += this->v->at(i);
		return ret;
	}
};


lli solve(lli x){
	lli inversion = 0;
	bit bt(e5);
	for(lli i = 1;i <= n;i++){
		b[i] = a[i] <= x ? -1 : 1;
	}
	for(lli i = 1;i <= n;i++){
		b[i] += b[i-1];
	}
	vll u(n+1);
	cerr << "!" << endl;
	for(lli i = 0;i <= n;i++) u[i] = b[i];
	sort(u.begin(), u.end());
	for(lli i = 0;i <= n;i++){
		m[u[i]] = i+1;
	}
	cerr << "!" << endl;
	for(lli i = 0;i <= n;i++){
		inversion += bt.sum(m[b[i]]);
		bt.add(m[b[i]],1);
	}
	return inversion;
}

int main(){
	cin >> n;
	l = n*(n+1)/2;
	for(lli i = 1;i <= n;i++) cin >> a[i];
	lli ans = INT_MAX;
	for(lli i = 1ll << 30;i > 0;i >>= 1){
		cerr << i << endl;
		lli ge = solve((ans^i));
		if(l-ge > ge) ans = ans^i;
	}
	cout << ans << endl;
}
