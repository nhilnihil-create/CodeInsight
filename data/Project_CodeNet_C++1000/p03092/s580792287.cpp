#include<iostream>
#include<string.h>
#define int long long
using namespace std;
const int N=5e3+2;
const int inf=1e18+2;
int dp[N],ar[N],lef[N],rig[N],pos[N],bit[N];
void upd(int pos){
	while(pos<N){
		bit[pos]++;
		pos+=(pos&-pos);
	}
}
int get(int idx){
	int sum=0;
	while(idx){
		sum+=bit[idx];
		idx-=(idx&-idx);
	}
	return sum;
}
int getsum(int l,int r){
	return get(r)-get(l-1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,i,j,k,l,a,b,ans=inf,idxans;
	cin>>n>>a>>b;
	for(i=1;i<=n;i++){
		cin>>ar[i];
		pos[ar[i]]=i;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<i;j++){
			if(ar[j]>ar[i]){
				lef[ar[i]]++;
			}
		}
		for(j=i+1;j<=n;j++){
			if(ar[j]>ar[i]){
				rig[ar[i]]++;
			}
		}
	}
	for(i=1;i<=n;i++){
		dp[i]=(i-1)*b;
		for(j=1;j<=n;j++){
			bit[j]=0;
		}
		for(j=i-1;j>=1;j--){
			if(pos[j]<pos[i]&&getsum(pos[j],pos[i])==0){
//				if(dp[j]+getsum(1,pos[j]-1)*a+getsum(pos[i]+1,n)*b<dp[i]){
//					trace[i]=j;
//				}
				dp[i]=min(dp[i],dp[j]+getsum(1,pos[j]-1)*a+getsum(pos[i]+1,n)*b);
			}
			upd(pos[j]);
		}
		if(rig[i]==0){
//			if(dp[i]+lef[i]*a<ans){
//				idxans=i;
//			}
			ans=min(ans,dp[i]+lef[i]*a);
		}
		//cout<<dp[i]+lef[i]*a<<' '<<dp[i]<<' '<<i<<' '<<rig[i]<<endl;
	}
//	while(idxans){
//		cout<<idxans<<' ';
//		idxans=trace[idxans];
//	}
	cout<<ans;
}