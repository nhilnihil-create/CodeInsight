// C - All Green
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
	int D,G; cin>>D>>G;
	int P[D], C[D];
	rep(i, D) cin>>P[i]>>C[i];
	int ans = INT_MAX;
	rep(bin, 1<<D){
		int cnt = 0, tot = 0, rest_max_bit = -1;
		rep(i, D)
			if(bin & 1<<i){
				int t = (i + 1)*100;
				tot += P[i]*t + C[i];
				cnt += P[i];
			}
			else rest_max_bit = i;
		if(tot < G){
			int t = (rest_max_bit + 1)*100;
			int p = (G - tot + t - 1)/t;
			if(p >= P[rest_max_bit]) continue;
			cnt += p;
		}
		ans = min(ans, cnt);
	}
	cout<< ans <<endl;
}
