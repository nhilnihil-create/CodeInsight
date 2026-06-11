#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62)

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



i64 n,m, Q, a[101010], b[101010], x[101010];
void solve(){
	cin >> n >> m >> Q;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}
	for(int i = 0; i < Q; i++){
		cin >> x[i];
	}
	
	for(int i = 0; i < Q; i++){
		i64* pal = (upper_bound(a+1,a+n,x[i])-1);
		i64* par = (lower_bound(a,a+n,x[i]));
		i64* pbl = (upper_bound(b+1,b+m,x[i])-1);
		i64* pbr = (lower_bound(b,b+m,x[i]));
		i64 al = abs(x[i] - *pal);
		i64 ar = abs(*par - x[i]);
		i64 bl = abs(x[i] - *pbl);
		i64 br = abs(*pbr - x[i]);
		al += min(abs(*(upper_bound(b+1,b+m,*pal)-1)-*pal), abs(*pal-*lower_bound(b,b+m,*pal)));
		ar += min(abs(*(upper_bound(b+1,b+m,*par)-1)-*par), abs(*par-*lower_bound(b,b+m,*par)));
		bl += min(abs(*(upper_bound(a+1,a+n,*pbl)-1)-*pbl), abs(*pbl-*lower_bound(a,a+n,*pbl)));
		br += min(abs(*(upper_bound(a+1,a+n,*pbr)-1)-*pbr), abs(*pbr-*lower_bound(a,a+n,*pbr)));
		cout << min({al,ar,bl,br}) << endl;
	}
}

int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}