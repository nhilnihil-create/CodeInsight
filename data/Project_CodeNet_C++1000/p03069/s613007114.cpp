#pragma target("avx")
#include<bits/stdc++.h>
using ll = int_fast64_t;
using P = std::pair<ll,ll>;
using V = std::vector<ll>;
template<typename T> using pq = std::priority_queue<T>;
template<typename T> using rpq = std::priority_queue<T, std::vector<T>, std::greater<T>>;

#define rep(i,b,e) for(ll i=b; i<e; i++)
#define be(vec) vec.begin(),vec.end()
#define print(vec) printf("[ ");for(auto &i:vec)printf("%ld ",i);puts("]");
#define scan(vec) for(auto &i:vec)scanf("%ld",&i)
#define fi first
#define se second

const int MOD = 1e9+7;
const ll INF = 1e18;
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

int main(){
	int n;
	scanf("%d", &n);
	int b[2+n], w[2+n];
	b[0] = w[0] = b[n+1] = w[n+1] = 0;
	getchar();
	rep(i, 1, n+1){
		if(getchar()=='#') b[i]=1, w[i]=0;
		else b[i]=0, w[i]=1;
	}
	rep(i, 0, n+1) b[i+1] += b[i];
	rep(i, 0, n+1) w[n-i] += w[n+1-i];
	int ans = 2e9;
	rep(i, 0, n+1){
		ans = std::min(ans, b[i]+w[i+1]);
	}
	printf("%d\n", ans);
	return 0;
}
