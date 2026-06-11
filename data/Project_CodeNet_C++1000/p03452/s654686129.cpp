#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repA(i, a, n) for(int i = a; i <= (n); ++i)
#define repD(i, a, n) for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a) memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e5 + 19;
vector <pair<int,int>> g[maxn];
vi x(maxn), v(maxn), cv;
int n,m;
bool possible = true;

int dfs(int i){
	v[i] = true;
	for(auto it: g[i]){
		if(!v[it.fst]){
			x[it.fst] = x[i] + it.snd;
			dfs(it.fst);
		}else if(x[it.fst] != x[i] + it.snd){
			possible = false;
		}
	}
	return 0;
}


int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	cin >> n >> m;
	rep(i,m){
		int l,r,d; cin >> l >> r >> d;
		l--; r--;
		g[l].pb(mp(r,d));
		g[r].pb(mp(l,-d));
	}
	rep(i,n){
		if(v[i] == 0){
			dfs(i);
		}	
	}
	if(possible){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}

	return 0;
}

