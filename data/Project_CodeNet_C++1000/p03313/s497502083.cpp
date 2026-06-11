#include <iostream>
#include <utility>
using namespace std;
typedef pair<int,int> pii;
pii mx(pii a, pii b){
	int i,ma1 = -1,ma2 = -1,c[4];
	c[0] = a.first,c[1] = a.second,c[2] = b.first,c[3] = b.second;
	for(i=0;i<4;i++){
		if(ma1<c[i]){
			ma2 = ma1; ma1 = c[i];
		}else if(ma2<c[i]){
			ma2 = c[i];
		}
	}
	return {ma1,ma2};
}
int a[1<<20];
pii dp[1<<20];
int main(){
	int i,j,n;
	cin >> n;
	for(i=0;i<(1<<n);i++){
		cin >> a[i];
		dp[i] = {a[i],0};
	}
	for(i=0;i<n;i++){
		for(j=0;j<(1<<n);j++){
			if(j&(1<<i)){
				dp[j] = mx(dp[j],dp[j^(1<<i)]);
			}
		}
	}
	int ans = a[0] + a[1];
	for(i=1;i<(1<<n);i++){
		ans = max(ans,dp[i].first + dp[i].second);
		cout << ans << endl;
	}
}