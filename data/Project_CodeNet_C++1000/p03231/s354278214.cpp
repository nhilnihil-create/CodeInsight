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
	ll n, m;
	scanf("%ld %ld", &n, &m);
	char s[n+1], t[m+1];
	scanf("%s %s", s, t);

	ll g = n * m / std::__gcd(n, m);
	ll x = g / n, y = g / m;
	bool cant = false;
	std::map<ll,char> mp;
	for(int i=0; i<n; i++){
		if(mp.find(x*i)!=mp.end()){
			if(mp[x*i]!=s[i]) cant = true;
		}else mp[x*i] = s[i];
	}
	for(int i=0; i<m; i++){
		if(mp.find(y*i)!=mp.end()){
			if(mp[y*i]!=t[i]) cant = true;
		}else mp[y*i] = t[i];
	}
	if(cant) puts("-1");
	else printf("%ld\n", g);
	return 0;
}
