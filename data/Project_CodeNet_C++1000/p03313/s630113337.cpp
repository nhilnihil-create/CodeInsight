#include<iostream>
using namespace std;
const int maxn=1<<18;
int n,up,mx[maxn],sec[maxn],dp[maxn];
void update(int i,int x){
	if(x>mx[i]){
		sec[i]=mx[i];
		mx[i]=x;
	}
	else if(x>sec[i]){
		sec[i]=x;
	}
}
signed main(){
	cin>>n;
	up=1<<n;
	for(int i=0;i<up;i++) cin>>mx[i];
	for(int j=0;j<n;j++){
		for(int i=0;i<up;i++){
			if((i>>j)&1){
				if(mx[i^(1<<j)]) update(i,mx[i^(1<<j)]);
				if(sec[i^(1<<j)]) update(i,sec[i^(1<<j)]);
			}
		}
	}
	for(int i=1;i<up;i++){
		dp[i]=max(dp[i-1],mx[i]+sec[i]);
		cout<<dp[i]<<endl;
	}
}