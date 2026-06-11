#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
#define rp(i,s,e) for(int i=(int)(s);i<(int)(e);++i)
#define chmin(x,y) x=min(x,(y))

int main(){
	int D,G; cin>>D>>G;
	G /= 100;
	vvi PC(D, vi(3));
	rp(i,0,D){
		cin>>PC[i][0]>>PC[i][1];
		PC[i][1] /= 100;
		PC[i][2] = (i+1)*PC[i][0] + PC[i][1];
	}

	// cout<<D<<" "<<G<<"\n";
	// rp(i,0,D)
	// 	cout<<PC[i][0]<<" "<<PC[i][1]<<" "<<PC[i][2]<<"\n";
	// cout<<"(1<<D)-1: "<<(1<<D)-1<<"\n";

	int ans = INT_MAX;
	int n = 1<<D;
	rp(bit, 1, n){
		int tot = 0;
		int cnt = 0;
		// cout<<bitset<10>(bit)<<"\n";
		rp(j, 0, D){
			if(bit & (1<<j)){
				cnt += PC[j][0]; // count
				tot += PC[j][2]; // total
			}
		}

		if(tot >= G) chmin(ans, cnt);

		rp(j, 0, D){
			if(bit & (1<<j)){
				int now_cnt = cnt - PC[j][0];
				int now_tot = tot - PC[j][2];
				// cout<<" j+1 "<<j+1;
				// cout<<" now_cnt "<<now_cnt;
				// cout<<" now_tot "<<now_tot;
				// cout<<"\n";
				rp(k, 1, PC[j][0]){ // [1,p-1]
					// cout<<" calc tot "<<now_tot + (j+1)*k;
					// cout<<" calc cnt "<<now_cnt + k;
					// cout<<"\n";
					if(now_tot + (j+1)*k >= G){
						chmin(ans, now_cnt + k);
					}
				}
			}
		}

	}

	// if(ans == INT_MAX){
	// 	puts("NG");
	// }
	// else{
		cout<< ans <<endl;
	// }
}
