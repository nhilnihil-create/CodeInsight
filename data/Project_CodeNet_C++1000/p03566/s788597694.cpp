#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RFOR(i,a,b) for(int i=(int)b-1;i>=(int)a;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
const int INF = 1e9 + 1;

int main() {
	int N;
	cin >> N;
	vector<double>T(N);
	vector<double>V(N);
	for (int i = 0;i<N;++i) {
		cin >> T[i];
	}
	for (int i = 0;i<N;++i) {
		cin >> V[i];
	}
	int Time = 0;
	for (int i = 0;i<N;++i) {
		Time += T[i];
	}
	vector<double>maxV(2*Time+1, (double)INF);

	int nowT = 0;
	for (int i = 0;i<N;++i) {
		for (int j = 0;j<T[i];++j) {
			int t1 = nowT + j * 2;
			int t2 = nowT + j * 2 + 1;
			maxV[t1] = min(maxV[t1], V[i]);
			maxV[t2] = min(maxV[t2], V[i]);
		}
		nowT += T[i] * 2;
		maxV[nowT] = min(maxV[nowT], V[i]);
	} 
	maxV[0] = 0.0;
	maxV[Time * 2] = 0.0;

	// 前から比較
	REP(ti, 2 * Time + 1) {
		maxV[ti + 1] = min(maxV[ti + 1], maxV[ti] + 0.5);
	}

	// 後ろから比較
	RREP(ti, 2 * Time + 1) {
		maxV[ti] = min(maxV[ti], maxV[ti + 1] + 0.5);
	}

	double ans = 0.0;
	REP(i, 2 * Time + 1) {
		// (上底 + 下底) * 高さ / 2
		ans += (maxV[i] + maxV[i + 1]) * 0.5 / 2.0;
	}

	printf("%.4f\n", ans);
	return 0;
}