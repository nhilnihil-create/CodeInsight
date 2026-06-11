// C - All Green
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	int D,G; cin>>D>>G;
	G /= 100;
	vector<int> P(D), C(D);
	rep(i, D){ cin>>P[i]>>C[i]; C[i]/=100; }
	int ans = INT_MAX;
	for(int bin=1; bin<(1<<D); ++bin){ // max<2^10=1024
		int cnt = 0, tot = 0;
		rep(i, D) // max=10
			if(bin & 1<<i){
				cnt += P[i]; // count
				tot += P[i]*(i+1) + C[i]; // total
			}
		if(tot < G) continue;
		ans = min(ans, cnt);
		rep(i, D)
			if(bin & 1<<i){
				int rest_g = G - (tot - P[i]*(i+1) - C[i]);
				int p = max(0, (rest_g+i)/(i+1)); // round up
				ans = min(ans, cnt - (P[i] - p));
			}
	}
	cout<< ans <<endl;
}
