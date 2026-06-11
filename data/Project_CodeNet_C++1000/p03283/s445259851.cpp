#pragma target("avx")
#pragma optimize("O3")
#include<bits/stdc++.h>
using ll = int_fast64_t;
using P = std::pair<ll,ll>;
using PP = std::pair<ll,P>;
using V = std::vector<ll>;
template<typename T> using pq = std::priority_queue<T>;
template<typename T> using rpq = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define REP(i,b,e) for(ll i=b; i<e; i++)
#define ALL(vec) vec.begin(),vec.end()
#define PRINT(vec) printf("[ ");for(auto &i:vec)printf("%ld ",i);puts("]");
#define SCAN(vec) for(auto &i:vec)scanf("%ld",&i)
#define fi first
#define se second

const int MOD = 1e9+7;
const ll INF = 1e18;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

int main(){
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	int rail[n+2][n+2] = {};
	REP(i, 0, m){
		int l, r;
		scanf("%d %d", &l, &r);
		rail[l][r]++;
	}

	REP(i, 0, n+2) for(ll j=n+1; j>0; j--)  rail[i][j-1] += rail[i][j];
	REP(i, 1, n+2) for(ll j=n+1; j>=0; j--) rail[i][j] += rail[i-1][j];

	REP(i, 0, q){
		int l, r, ans = 0;
		scanf("%d %d", &l, &r);
		ans = rail[n+1][0] - rail[l-1][0] - rail[n+1][r+1] + rail[l-1][r+1];
		printf("%d\n", ans);
	}
	return 0;
}

