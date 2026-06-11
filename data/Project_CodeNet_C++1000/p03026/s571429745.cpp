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
	int n, a, b;
	scanf("%d", &n);
	P edges[n];
	std::vector<int> links[n];
	REP(i, 0, n-1){
		scanf("%d %d", &a, &b);
		edges[i] = P(a-1, b-1);
		links[a-1].push_back(b-1);
		links[b-1].push_back(a-1);
	}
	int c[n];
	REP(i, 0, n) scanf("%d", &c[i]);
	std::sort(c, c+n, std::greater<int>());

	std::queue<int> que;
	int pos = 0, sum = 0, used[n] = {}, num[n];
	que.push(0);
	while(!que.empty()){
		int from = que.front();
		que.pop();
		if(used[from]) continue;
		used[from] = true;
		sum += c[pos];
		num[from] = c[pos++];
		for(int next: links[from]){
			if(used[next]) continue;
			que.push(next);
		}
	}
	
	printf("%d\n", sum-num[0]);
	REP(i, 0, n) printf("%d ", num[i]);
	return 0;
}

