#include<bits/stdc++.h>
using namespace std;
long long n,ans=1e9,a[200005],sum[200005];
long search1(long l,long r){
	long idx1=l, idx2=r;
	while(l+1<r){
		long mid=(l+r)/2;
		if(sum[mid]-sum[idx1-1]<=sum[idx2]-sum[mid]){
			l=mid;
		}else{
			r=mid;
		}
	}
	if(sum[r]-sum[idx1-1]<=sum[idx2]-sum[r]){
		return r;
	}else{
		if(sum[l]-sum[idx1-1]<=sum[idx2]-sum[l]){
			return l;
		}else{
			return -1;
		}
	}
}
long search2(long l,long r){
	long idx1=l, idx2=r;
	while(l<r){
		long mid=(l+r)/2;
		if(sum[mid]-sum[idx1-1]>sum[idx2]-sum[mid]){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	if(sum[l]-sum[idx1-1]>sum[idx2]-sum[l]){
		return l;
	}else{
		return -1;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=2;i<=n-2;i++){
		long pos1=search1(1,i);
		long pos2=search2(1,i);
		long pos3=search1(i+1,n);
		long pos4=search2(i+1,n);
		if(pos1!=-1 && pos3!=-1){
			long long hah1=max(sum[pos1],max(sum[i]-sum[pos1],max(sum[pos3]-sum[i],sum[n]-sum[pos3])));
			long long hah2=min(sum[pos1],min(sum[i]-sum[pos1],min(sum[pos3]-sum[i],sum[n]-sum[pos3])));
			ans=min(ans,hah1-hah2);
		}
		if(pos1!=-1 && pos4!=-1){
			long long hah1=max(sum[pos1],max(sum[i]-sum[pos1],max(sum[pos4]-sum[i],sum[n]-sum[pos4])));
			long long hah2=min(sum[pos1],min(sum[i]-sum[pos1],min(sum[pos4]-sum[i],sum[n]-sum[pos4])));
			ans=min(ans,hah1-hah2);
		}
		if(pos2!=-1 && pos3!=-1){
			long long hah1=max(sum[pos2],max(sum[i]-sum[pos2],max(sum[pos3]-sum[i],sum[n]-sum[pos3])));
			long long hah2=min(sum[pos2],min(sum[i]-sum[pos2],min(sum[pos3]-sum[i],sum[n]-sum[pos3])));
			ans=min(ans,hah1-hah2);
		}
		if(pos2!=-1 && pos4!=-1){
			long long hah1=max(sum[pos2],max(sum[i]-sum[pos2],max(sum[pos4]-sum[i],sum[n]-sum[pos4])));
			long long hah2=min(sum[pos2],min(sum[i]-sum[pos2],min(sum[pos4]-sum[i],sum[n]-sum[pos4])));
			ans=min(ans,hah1-hah2);
		}
	}
	cout<<ans;
}