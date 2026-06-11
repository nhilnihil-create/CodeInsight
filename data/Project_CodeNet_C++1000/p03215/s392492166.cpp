#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int N;
vector<ll> a,s;

void dfs(ll p, ll x) {
	if(x != 0)
		s.push_back(x);
	if(p == N)
		return;

	dfs(p+1, x+a.at(p));
	if(x == 0)
		dfs(p+1, 0);
}

int main() {
	ll K,r=0;
	cin >> N >> K;
	a.resize(N);

	rep(i,N)
		cin >> a.at(i);
	dfs(0,0);
	
	rep(i,40) {
		ll t=(1ll<<(39-i))+r, c=0;

		rep(j,s.size())
			if(t == (t&s.at(j)))
				++c;

		if(c >= K)
			r = t;
	}
	
	cout << r << endl;
}