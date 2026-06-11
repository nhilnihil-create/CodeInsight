#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int64 i = 0;i < (n);i++)
#define FOR(i, a, b) for(int64 i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int32 H, W, N;
	cin >> H >> W >> N;
	vector<PII> v(N);
	REP(i, v.size()){
		cin >> v[i].fs >> v[i].sc;
	}
	sort(all(v));
	int32 nowy = 1;
	int32 res = H;
	REP(i, N){
		if(i > 0){
			nowy += max(v[i].fs-v[i-1].fs-1, (int32)0);
		}else{
			nowy += max(v[i].fs-2, (int32)0);
		}
		if(nowy >= v[i].sc){
			res = min(res, v[i].fs-1);
		}
		bool ok = v[i].sc-1 != nowy;
		while(v[i].fs == v[i+1].fs){
			i++;
			ok = ok && (v[i].sc-1 != nowy);
		}
		if(ok && (v[i].fs > 0)) nowy++;
	}
	cout << res << endl;
}
