#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define int ll
const int N=200001;
int n,a[N],h[N],dp[N];
#define all(x) x.begin(),x.end()
struct segment{
	int seg[200001*4]={0};
	int pull(int x,int y){
		return max(seg[x],seg[y]);
	}
	void update(int id,int l,int r,int i,int v){
		if(l==r){
			seg[id]=max(seg[id],v);
			return;
		}
		int m=(l+r)/2;
		if(i<=m)update(id*2+1,l,m,i,v);
		else update(id*2+2,m+1,r,i,v);
		seg[id]=pull(id*2+1,id*2+2);
	}
	int query(int id,int l,int r,int ql,int qr){
		if(qr<l||r<ql)return 0;
		if(ql<=r&&r<=qr)return seg[id];
		int m=(l+r)/2;
		return max(query(id*2+1,l,m,ql,qr),query(id*2+2,m+1,r,ql,qr));
	}	
	
}seg;
void bi(){
	vector<int> tmp(h,h+n);
	sort(all(tmp));
	tmp.resize(unique(all(tmp))-tmp.begin());
	for(int i=0;i<n;i++){
		h[i]=upper_bound(all(tmp),h[i])-tmp.begin()-1;
	}
}
signed main(){
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>h[i];
	for(int i=0;i<n;i++)cin>>a[i];
	bi();
	dp[0]=a[0];
	seg.update(0,0,n-1,h[0],a[0]);	
	int ans=a[0];
	for(int i=1;i<n;i++){
		dp[i]=seg.query(0,0,n-1,0,h[i]-1)+a[i];
		seg.update(0,0,n-1,h[i],dp[i]);
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	
}