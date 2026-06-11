// C - All Green
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
#define rp(i,s,e) for(int i=(int)(s);i<(int)(e);++i)
#define chmin(x,y) x=min(x,(y))

int main(){
	int D,G; cin>>D>>G;
	vvi PC(D, vi(2)); // <count, bonus>
	rp(i, 0,D ) cin>>PC[i][0]>>PC[i][1];

	int ans = INT_MAX;
	int n = 1<<D;
	rp(bit, 1, n){

		int cnt = 0, tot = 0;
		rp(j, 0, D)
			if(bit & (1<<j)){
				cnt += PC[j][0]; // count
				tot += PC[j][0] * (j+1) * 100 + PC[j][1]; // total
			}
		if(tot >= G) chmin(ans, cnt);

		rp(j, 0, D)
			if(bit & (1<<j)){
				int now_cnt = cnt - PC[j][0];
				int now_tot = tot - (PC[j][0] * (j+1) * 100 + PC[j][1]);
				rp(k, 1, PC[j][0]) // [1,p-1]
					if(now_tot+(j+1)*k*100 >= G) chmin(ans, now_cnt + k);
			}

	}
	cout<< ans <<endl;
}
