#include<bits/stdc++.h>
typedef long long int ll;
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int limit = 2e5;

using namespace std;

vector<ll> h(limit,0);
vector<ll> b(limit,0);
vector<ll> tree(4*limit,0);

ll max(ll a,ll b){
  if(a>b)
    return a;
  return b;
}

void updateTree(ll node,ll l,ll r,ll height,ll val){
	if(l==r){
		tree[node] = max(tree[node],val);
		return;
	}
	ll mid=(l+r)/2;
	if(mid>=height)
		updateTree(2*node,l,mid,height,val);
	else
		updateTree(2*node+1,mid+1,r,height,val);

	tree[node] = max(tree[2*node],tree[2*node+1]);
}

ll queryTree(ll node,ll l,ll r,ll ql,ll qr){
	if(ql<=l && qr>=r)
		return tree[node];
	
	if(qr<l || ql>r)
		return 0;

	ll mid = (l+r)/2;
	ll left = queryTree(2*node,l,mid,ql,qr);
	ll right = queryTree(2*node+1,mid+1,r,ql,qr);
	return max(left,right);
}


int main(){
	ll n,i,m=0;
	cin>>n;

	for(i=0;i<n;i++)
		cin>>h[i];
	for(i=0;i<n;i++)
		cin>>b[i];

	vector<ll> dp(n,0);
	//memset(tree,0,sizeof(tree));
	dp[0]=b[0];
	m=max(m,dp[0]);
	updateTree(1,1,n,h[0],dp[0]);

	for(i=1;i<n;i++){
		dp[i]=b[i]+queryTree(1,1,n,0,h[i]-1);
		m=max(m,dp[i]);
        updateTree(1,1,n,h[i],dp[i]);
	}

	cout<<m<<endl;

}