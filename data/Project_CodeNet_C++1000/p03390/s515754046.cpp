#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int i = 0;i < (n);i++)
#define FOR(i, a, b) for(int i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-6;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

const int64 mod = 1e9+7;

int64 mysqrt(int64 x){
	int64 l = 0, r = INF+1, m;
	while(r-l > 1){
		m = l+(r-l)/2;
		if(m*m < x) l = m;
		else r = m;
	}
	return l;
}

int main(void){
	int32 Q;
	cin >> Q;
	REP(_, Q){
		int64 a, b;
		cin >> a >> b;
		if(a > b) swap(a, b);
		int64 x = mysqrt(a*b);
		if(a == b || a+1 == b){
			cout << 2*a-2 << endl;
		}else if(x*(x+1) >= a*b){
			cout << 2*x-2 << endl;
		}else{
			cout << 2*x-1 << endl;
		}
	}
}