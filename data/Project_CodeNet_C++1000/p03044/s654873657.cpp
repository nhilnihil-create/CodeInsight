#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

ll N;
// next, cost
vector<pair<ll, ll> > to[100005];

#define SIRO 1
#define KURO 2

ll ans[100005];

void dfs(ll pa, ll cur, ll color) {
	ans[cur] = color;
	for(pair<ll, ll> next: to[cur]) {
		if(pa == next.first) continue;
		if(next.second % 2 == 0) {
			dfs(cur, next.first, color);
		} else {
			ll nc;
			if(color == KURO) {
				nc = SIRO;
			} else {
				nc = KURO;
			}
			dfs(cur, next.first, nc);
		}
	}
}


int main(){
	cin >> N;
	rep(i, N - 1) {
		ll u, v, w;
		cin >> u >> v >> w;
		u--;v--;
		to[u].push_back(make_pair(v, w));
		to[v].push_back(make_pair(u, w));
	}

	dfs(-1, 0, KURO);



	rep(i, N) {
		if(ans[i] == SIRO) {
			cout << 0 << endl;
		} else {
			cout << 1 << endl;
		}
	}


}
