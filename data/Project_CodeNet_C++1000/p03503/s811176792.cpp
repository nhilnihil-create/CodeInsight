// C - Shopping Street
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
#define rp(i,s,e) for(int i=(int)(s);i<(int)(e);++i)

int c(int open_pattern, vi &fi){
	int ret = 0;
	rp(j, 0, 10) if(open_pattern>>j & 1 && fi[j]) ret++;
	return ret;
}

int main(){
	int n; cin>>n;
	vvi F(n, vi(10));
	rp(i, 0, n) rp(j, 0, 10) cin>>F[i][j];
	vvi P(n, vi(10+1));
	rp(i, 0, n) rp(j, 0, 10+1) cin>>P[i][j];
	int64_t ans = -10000000*100;
	rp(i, 1, 1<<10){
		int64_t s = 0;
		rp(j, 0, n) s += P[j][c(i, F[j])];
		ans = max(ans, s);
	}
	cout<< ans <<endl;
}
