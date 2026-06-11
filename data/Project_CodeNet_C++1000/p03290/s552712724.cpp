// C - All Green
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	int D,G; cin>>D>>G;
	vector<int> P(D), C(D);
	rep(i, D) cin>>P[i]>>C[i];

	int ans = INT_MAX;
	for(int bin=1; bin<(1<<D); ++bin){ // max<2^10=1024

		int cnt = 0, tot = 0;
		rep(j, D) // max=10
			if(bin & 1<<j){
				cnt += P[j]; // count
				tot += P[j]*(j+1)*100 + C[j]; // total
			}
		if(tot < G) continue;

		ans = min(ans, cnt);
		rep(j, D)
			if(bin & 1<<j){
				int now_cnt = cnt;
				int now_tot = tot - C[j];
				rep(k, P[j]-1){ // max=100, delete p-1 times
					now_cnt--;
					now_tot -= (j+1)*100;
					if(now_tot >= G) ans = min(ans, now_cnt);
				}
			}

	}
	cout<< ans <<endl;
}
