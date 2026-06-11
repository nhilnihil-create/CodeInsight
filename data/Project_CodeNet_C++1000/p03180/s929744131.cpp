#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
const int MAXN=1<<18;
LL dp[MAXN],a[32][32];
LL n;

int loc(int x){
	int cnt=0;
	while(x>1){
		x>>=1;
		cnt++;
	}
	return cnt;
}

int lowbit(LL x){
	return x&-x;
}

LL cal(LL x,LL y){
	int lx=loc(x);
	LL tot=0;
	while(y){
		int ly=loc(lowbit(y));
		y-=lowbit(y);
		tot+=a[lx][ly];
	}
	return tot;
}

void init(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=3,up=2;i<(1<<n);i++){
		if(up==i>>1) up<<=1;
		dp[i]=dp[i-up]+cal(up,i-up);
	}
}

void work(){
	for(int i=1;i<(1<<n);i++){
		for(int j=1;j<=i;j++){
			if((i|j)==i){
				dp[i]=max(dp[i],dp[j]+dp[i^j]);
			}
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
}

int main(){
	init();
	work();
	return 0;
}
