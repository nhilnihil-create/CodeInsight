#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(a) cout<<#a<<":"<<a<<endl;
const ll INF=0x3f3f3f3f;
const ll N=1e6+7;
const ll mod=1e9+7;
ll maxn,minn;
ll T,n,m;
ll W[N];
ll V[N];
ll dp[N];

struct aa{
	ll l,r,v;
}ans[N];

void build_tree(ll node,ll start,ll end){
	ans[node].l=start;
	ans[node].r=end;
    if(start==end){
        ans[node].v=0;
        return ;
    }
    ll left_node=2*node;
    ll right_node=2*node+1;
    ll mid=(start+end)>>1;
    build_tree(left_node,start,mid);
    build_tree(right_node,mid+1,end);
    ans[node].v=max(ans[left_node].v,ans[right_node].v);
}

void update(ll node,ll p,ll v){
    if(ans[node].l==ans[node].r){
        ans[node].v=v;
        return ;
    }
    ll mid=(ans[node].l+ans[node].r)>>1;
    ll left_node=2*node;
    ll right_node=2*node+1;
    if(p<=mid){
        update(left_node,p,v);
    }
    else{
        update(right_node,p,v);
    }
    ans[node].v=max(ans[left_node].v,ans[right_node].v);
}
ll query(ll node,ll l,ll r){
    if(r<ans[node].l||l>ans[node].r){
        return 0;
    }
    else if(ans[node].l>=l&&ans[node].r<=r){
        return ans[node].v;
    }
	ll mid=(ans[node].l+ans[node].r)>>1;    
	ll left_node=2*node;
	ll right_node=2*node+1;
	ll sum_left=query(left_node,l,r);
	ll sum_right=query(right_node,l,r);
	return max(sum_left,sum_right);
}

int main(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		scanf("%lld",W+i);
	}
	for(ll i=1;i<=n;i++){
		scanf("%lld",V+i);
	}
	build_tree(1,1,n);
	ll a;
	for(ll i=1;i<=n;i++){
		a=query(1,1,W[i]);
		dp[i]=V[i]+a;
		maxn=max(maxn,dp[i]);
		update(1,W[i],dp[i]);
	}
	cout<<maxn<<endl;
	
	return 0;
}



