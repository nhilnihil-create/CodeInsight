#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx2")

#include <bits/stdc++.h>

using namespace std;

typedef long long lo;
typedef pair< lo,lo > PII;

#define fi first
#define se second
#define mp make_pair
#define int long long
#define endl "\n"
#define pb push_back
#define fio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR for(int i=1;i<=n;i++)
#define mid ((start+end)/2)
#define ort ((bas+son)/2)

const lo inf = 1000000000000000000;
const lo KOK = 100000;
const lo LOG = 30;
const lo li = 500005;
const lo mod = 1000000007;

int n,m,b[li],a[li],k,flag,t,tree[li*4],lazy[li*4],dp[li];
int cev;
string s;
vector<int> v;

inline void push(int node,int start,int end){
	if(lazy[node]==0)return ;
	tree[node]=max(tree[node],lazy[node]);
	if(start!=end){
		lazy[node*2]=max(lazy[node*2],lazy[node]);
		lazy[node*2+1]=max(lazy[node*2+1],lazy[node]);
	}
	lazy[node]=0;
}

inline void update(int node,int start,int end,int l,int r,int val){
	push(node,start,end);
	if(start>end || start>r || end<l)return ;
	if(start>=l && end<=r){
		lazy[node]=max(lazy[node],val);
		push(node,start,end);
		return ;
	}
	update(node*2,start,mid,l,r,val),update(node*2+1,mid+1,end,l,r,val);
	tree[node]=max(tree[node*2],tree[node*2+1]);
}

inline int query(int node,int start,int end,int l,int r){
	if(start>end || start>r || end<l)return 0;
	push(node,start,end);
	if(start>=l && end<=r){
		return tree[node];
	}
	return max(query(node*2,start,mid,l,r),query(node*2+1,mid+1,end,l,r));
}

main(void){
	scanf("%lld",&n);
	FOR scanf("%lld",&b[i]);
	FOR scanf("%lld",&a[i]);
	FOR{
		dp[i]=query(1,1,200000,b[i],b[i]);
		dp[i]+=a[i];
		update(1,1,200000,b[i],200000,dp[i]);
		cev=max(cev,dp[i]);
	}
	printf("%lld\n",cev);
	return 0;
}

