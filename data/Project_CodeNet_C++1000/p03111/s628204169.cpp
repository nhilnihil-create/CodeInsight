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

int n, a, b, c, l[8];

int rec(int A, int B, int C, int x, int mp){
	x--;
	if(x<0){
		if(A*B*C==0) return 1e9;
		return mp + abs(a-A) + abs(b-B) + abs(c-C) - 30;
	}

	return std::min({
		rec(A+l[x], B, C, x, mp+10),
		rec(A, B+l[x], C, x, mp+10),
		rec(A, B, C+l[x], x, mp+10),
		rec(A, B, C, x, mp)
	});
}

int main(){
	scanf("%d %d %d %d", &n, &a, &b, &c);
	REP(i, 0, n) scanf("%d", &l[i]);
	printf("%d\n", rec(0, 0, 0, n, 0));
	return 0;
}


