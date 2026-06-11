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
#define PRINT(vec) printf("[ ");for(auto &i:vec)printf("%d ",i);puts("]");
#define SCAN(vec) for(auto &i:vec)scanf("%ld",&i)
#define fi first
#define se second

const int MOD = 1e9+7;
const ll INF = 1e18;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

int main(){
	int n;
	scanf("%d", &n);
	std::bitset<10> f[n];
	REP(i, 0, n){
		REP(j, 0, 10){
			getchar();
			if(getchar()%2) f[i].set(j);
			else f[i].reset(j);
		}
	}
	
	int p[n][11];
	REP(i, 0, n) REP(j, 0, 11) scanf("%d", &p[i][j]);

	int c[n], ans = -1e9;
	REP(i, 1, 1<<10){
		memset(c, 0, sizeof(c));
		REP(j, 0, 10) if((i>>j)&1) {
			REP(I, 0, n) if(f[I][j]) {
				c[I]++;
			}
		}
		int tmp = 0;
		REP(I, 0, n) tmp += p[I][c[I]];
		if(ans<tmp) ans = tmp;
	}

	printf("%d\n", ans);
	return 0;
}

