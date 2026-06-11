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

ll digi_sum(ll x){
	ll ret = 0;
	while(x){
		ret += x%10;
		x /= 10;
	}
	return ret;
}

int main(){
	std::string s;
	std::cin >> s;
	int c1 = 0, c2 = 0;
	REP(i, 0, s.size()){
		c1 += s[i]-'0';
		if(i==0) c2 += s[i]-'1';
		else c2 += 9;
	}
	printf("%d\n", std::max(c1, c2));
	return 0;
}

