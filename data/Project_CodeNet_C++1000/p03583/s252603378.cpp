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
	int n;
	scanf("%d", &n);
	REP(i, 1, 3501) REP(j, 1, 3501) {
		// 1/k = 4/n - 1/i - 1/j;
		// k = n*i*j / (4*i*j - n*j - n*i);
		ll bunsi = n*i*j, bunbo = 4*i*j - n*j - n*i;
		if(bunbo<=0) continue;
		if(bunsi%bunbo==0){
			printf("%ld %ld %ld\n", i, j, bunsi/bunbo);
			return 0;
		}
	}
	return 0;
}

