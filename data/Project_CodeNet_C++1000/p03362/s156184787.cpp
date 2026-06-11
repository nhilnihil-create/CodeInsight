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
	std::vector<bool> isPrime(60000, true);
	isPrime[0] = isPrime[1] = false;
	V primes;
	REP(i, 2, 60000) if(isPrime[i]) {
		for(int j=i+i; j<60000; j+=i){
			isPrime[j] = false;
		}
		primes.push_back(i);
	}

	int n;
	scanf("%d", &n);
	for(ll x: primes){
		if(x%5==1){
			printf("%ld ", x);
			if(--n==0) break;
		}
	}
	return 0;
}

