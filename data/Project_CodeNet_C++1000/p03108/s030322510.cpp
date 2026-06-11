#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(ll i = 0; i<(ll)(n); i++)
#define REPS(i,n) for (ll i = 1; i<=(ll)(n); i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define MOD 1000000007
#define MOD2 998244353
#define PI 3.141592653

struct UnionFind { //leaderのtableが部下の数を返すtype
	vector<ll> table;

	UnionFind(ll n) : table(n) { //tableはleaderなら部下の数、そうでなければ所属する上司
		for (ll i = 0; i < n; i++) table[i] = -1;
	}
	
	ll find(ll x){ //leaderの番号を返す
		if (table[x] < 0){
			return x; //tableの値が負の場合はleaderなので自分
		}
		else{
			table[x] = find(table[x]); //xのleader
			return table[x];
		}
	}

	void unite(ll x, ll y){ //xとyをつなげる
		ll s1 = find(x); //xのleader
		ll s2 = find(y); //yのleader
		if (s1 != s2){ 
			if (table[s1] > table[s2]){ //xの木のほうが長い場合はxにyをくっつける
				table[s2] += table[s1];
				table[s1] = s2;
			}
			else if (table[s2] > table[s1]){
				table[s1] += table[s2];
				table[s2] = s1;
			}
			else{
				table[s1] += table[s2];
				table[s2] = s1;
			}
		}
		return;
	}
}; //structの最後には;が必要!!

int main(){
	ll n, m, x, y, a, b; cin >> n >> m;
	vector<ll> ansl(m);
	vector<vector<ll>> conn(m,vector<ll>(2));
	REP(i,m) {
		cin >> a >> b;
		conn[m-1-i][0]=a-1;
		conn[m-1-i][1]=b-1;
	}
	UnionFind uf(n);
	REP(i,m){
		x = uf.table[uf.find(conn[i][0])];
		y = uf.table[uf.find(conn[i][1])];
		if (i==0) ansl[i] = x*y;
		else {
			if (uf.find(conn[i][0])!=uf.find(conn[i][1])){
				ansl[i] = ansl[i-1]+x*y;
			}
			else{
				ansl[i] = ansl[i-1];
			}
		}
		uf.unite(conn[i][0],conn[i][1]);
	}
	FORD(i,m-2,0){
		cout << ansl[m-1]-ansl[i] << endl;
	}
	cout << ansl[m-1] << endl;
}