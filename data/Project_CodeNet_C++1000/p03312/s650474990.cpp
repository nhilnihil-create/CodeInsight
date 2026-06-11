#include<iostream>
#include<algorithm>
using namespace std;
long long inf=1e12;
int n;
long long a[200005],sum[200005],ans;
long long check(int f,int s,int t){
	if(!f||f>s||t<=s||t==n){
		return inf;
	}
	long long x1=sum[f],x2=sum[s]-sum[f],x3=sum[t]-sum[s],x4=sum[n]-sum[t];
	return max(max(x1,x2),max(x3,x4))-min(min(x1,x2),min(x3,x4));
}
int main(){
	cin>>n;
	ans=inf;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=2,l,r;i<=n-2;i++){
		l=upper_bound(sum,sum+n+1,sum[i]/2)-sum;
		if(l==0) l++;
		if(l==n+1) l--;
		r=upper_bound(sum,sum+n+1,sum[i]+(sum[n]-sum[i])/2)-sum;
		if(r==0) l++;
		if(r==n+1) r--;
		for(int j=l-1;j<=l;j++){
			for(int k=r-1;k<=r;k++){
				ans=min(ans,check(j,i,k));
			}
		}
	}
	cout<<ans;
}