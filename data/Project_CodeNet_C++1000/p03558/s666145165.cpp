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

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

const int64 mod = 1e9+7;
using PIC = pair<int32, char>;

vector<vector<PII>> G;
int main(void){
	int32 K;
	cin >> K;
	G.resize(K);
	REP(i, K){
		G[i].push_back({0, i*10%K});
		G[i].push_back({1, (i+1)%K});
	}
	vector<int32> d(K, INF);
	d[1] = 1;
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push({0, 1});
	while(pq.size()){
		int32 dd, vv;
		tie(dd, vv) = pq.top(); pq.pop();
		if(dd > d[vv]) continue;
		REP(i, G[vv].size()){
			if(d[G[vv][i].sc] > d[vv]+G[vv][i].fs){
				d[G[vv][i].sc] = d[vv]+G[vv][i].fs;
				pq.push({d[G[vv][i].sc], G[vv][i].sc});
			}
		}
	}
	cout << d[0] << endl;
}