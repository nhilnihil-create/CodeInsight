#include<iostream>
#define int long long
using namespace std;
const int N=2e5+2;
const int inf=1e18+7;
int ar[N],sum[N],pos[N],pos1[N];
int getsum(int l,int r){
	return sum[r]-sum[l-1];
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,i,j,k,l,ans=inf;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>ar[i];
		sum[i]=sum[i-1]+ar[i];
	}
	pos[2]=1;
	for(i=3;i<=n;i++){
		pos[i]=pos[i-1];
		while(pos[i]+1<i&&abs(getsum(1,pos[i])-getsum(pos[i]+1,i))>abs(abs(getsum(1,pos[i]+1)-getsum(pos[i]+2,i)))){
			pos[i]++;
		}
		//cout<<pos[i]<<" ";
	}
	//cout<<endl;
	pos1[n-1]=n;
	for(i=n-2;i>=1;i--){
		pos1[i]=pos1[i+1];
		while(pos1[i]-1>i&&abs(getsum(pos1[i],n)-getsum(i,pos1[i]-1))>abs(getsum(pos1[i]-1,n)-getsum(i,pos1[i]-2))){
			pos1[i]--;
		}
		//cout<<pos1[i]<<" ";
	}
	//cout<<endl;
	for(i=2;i<n-1;i++){
ans=min(ans,max(max(sum[pos[i]],sum[i]-sum[pos[i]]),max(sum[pos1[i+1]-1]-sum[i],sum[n]-sum[pos1[i+1]-1]))-min(min(sum[pos[i]],sum[i]-sum[pos[i]]),min(sum[pos1[i+1]-1]-sum[i],sum[n]-sum[pos1[i+1]-1])));
	}
	cout<<ans;
}