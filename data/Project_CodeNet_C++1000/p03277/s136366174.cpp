#include<bits/stdc++.h>
#define f first
#define s second
#define ll long long
#define N 500009
#define inf 999999999999
#define pb push_back
#define M (L+R)/2
using namespace std;
 
struct node {
	ll sum;
	node *left,*right;
	node(): sum(0), left(NULL), right(NULL){}
};
node *root(NULL);
 
void upd(node *&parent,ll L,ll R,ll ind,ll x){
	if(!parent){
		parent=new node();
	}
	if(L+1==R){
		parent->sum+=x;
		return;
	}
	if(ind<M){
		upd(parent->left,L,M,ind,x);
	} else {
		upd(parent->right,M,R,ind,x);
	}
	parent->sum=(parent->left?parent->left->sum:0)+(parent->right?parent->right->sum:0);
	return;
}
 
ll get(node *&parent,ll L,ll R,ll l,ll r){
	if(parent){
		if(L>=r || R<=l)return 0;
		if(l<=L && R<=r)return parent->sum;
		return get(parent->left,L,M,l,r)+get(parent->right,M,R,l,r);
	}
	return 0;
}
 
 
ll n,A[N],a[N],b[N],c[N];
 
bool check(ll x){
	ll zero=0,one=0;
	for(int i=1;i<=n;i++){
		if(a[i]<x)b[i]=-1;
		else b[i]=1;
	}
	for(int i=1;i<=n;i++){
		b[i]+=b[i-1];
		if(b[i]<0)zero++;
		else one++;
		upd(root,-2*N,2*N,b[i],1);
	}
	for(int i=1;i<=n;i++){
		upd(root,-2*N,2*N,b[i],-1);
		ll G=get(root,-2*N,2*N,b[i],N-1);
		one+=G;
		zero+=n-i-G;
	}
	
	if(zero>one)return false;
	else return true;
}
 
int main(){
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		A[i]=a[i];
	}
	sort(A+1,A+1+n);
	ll L=1,R=n,pas=0;
	while(L<=R){
		root=NULL;
		if(check(A[M])){
			pas=A[M];
			L=M+1;
		} else {
			R=M-1;
		}
	}
	cout<<pas<<endl;
	return 0;
}
