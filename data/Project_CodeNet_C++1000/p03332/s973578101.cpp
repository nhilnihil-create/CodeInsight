#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

const int MAX_COMB = 3e5 + 3;
const LL mod = 998244353;
LL fct[MAX_COMB+1];
LL invfct[MAX_COMB+1];

void build(){
	fct[0] = fct[1] = 1;
	repp(i,2,MAX_COMB+1){
		fct[i] = fct[i-1] * i % mod;
	}
	LL x = fct[MAX_COMB];
	invfct[MAX_COMB] = 1;
	for(int i = mod - 2 ; i > 0 ; i >>= 1){
		if(i % 2 == 1) (invfct[MAX_COMB] *= x) %= mod;
		(x *= x) %= mod;
	}
	repm(i,MAX_COMB,0){
		invfct[i-1] = invfct[i] * i % mod;
	}
}

LL comb(int x, int y){
	if(x < 0 || y < 0 || x < y) return 0;
	return fct[x] * invfct[y] % mod * invfct[x-y] % mod;
}

int main(){
	build();
	LL N,A,B,K; cin >> N >> A >> B >> K;
	LL ans = 0;
	repp(i,0,N+1) if(K >= A*i && (K-A*i)%B == 0){
		(ans += comb(N,i)*comb(N,(K-A*i)/B)) %= mod;
	}
	cout << ans << endl;
	return 0;
}
