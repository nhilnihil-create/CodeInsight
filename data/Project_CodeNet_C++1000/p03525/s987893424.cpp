#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(void){
	int N;
	cin >> N;
	vector<int> D(N);
	rep(i,N)cin >> D[i];
	sort(ALL(D));
	vector<int> c(25);
	c[0]++;
	rep(i,N){
		if(i%2==0){
			c[D[i]]++;
		}else{
			c[(24-D[i])%24]++;
		}
	}
	rep(i,24){
		if(c[i]>=2){
			cout << 0 << endl;
			return 0;
		}
	}
	int ans = 24;
	rep(i,24)rep(j,24){
		if(i==j)continue;
		if(c[i]&&c[j]){
			int dis = min(abs(i-j),min(24-i+j,24-j+i));
			ans = min(ans,dis);
		}
	}
	cout << ans << endl;
}