#pragma target("avx")
#include<bits/stdc++.h>
using ll = int_fast64_t;
using P = std::pair<ll,ll>;
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
	std::map<int,int> mp;
	REP(x, 0, n+1){
		int y = x;
		for(int i=2; i*i<=y; i++){
			while(y%i==0){
				mp[i]++;
				y /= i;
			}
		}
		if(y>1) mp[y]++;
	}

	ll ans = 0;

	int ar2=0, ov4=0;
	for(auto p: mp){
		if(p.se>=4) ov4++;
		else if(p.se>=2) ar2++;
	}
	ans += ov4*(ov4-1)/2 * ar2;
	ans += ov4*(ov4-1)/2 * (ov4-2);

	int ov24 = ar2 = 0;
	for(auto p:mp){
		if(p.se>=24) ov24++;
		else if(p.se>=2) ar2++;
	}
	ans += ov24*(ov24-1);
	ans += ov24*ar2;

	int ar4=0, ov14=0;
	for(auto p:mp){
		if(p.se>=14) ov14++;
		else if(p.se>=4) ar4++;
	}
	ans += ov14*(ov14-1);
	ans += ov14*ar4;

	int ov74 = 0;
	for(auto p:mp){
		if(p.se>=74) ov74++;
	}
	ans += ov74;

	printf("%ld\n", ans);
	return 0;
}
