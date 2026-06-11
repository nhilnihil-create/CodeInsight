#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store") // to restrict undesirable precision
#pragma GCC optimize ("-fno-defer-pop")// to pop argument of function as soon as it returns
#define all(a) a.begin(),a.end()
#define ll long long int
#define ld long double
ll power(ll a,ll b,ll m){ if(b==0) return 1; if(b==1) return a%m; ll t=power(a,b/2,m)%m; t=(t*t)%m; if(b&1) t=((t%m)*(a%m))%m; return t;}
ll modInverse(ll a, ll m) { return power(a, m-2, m); }
#define ps push_back
#define fs first
#define sc second
#define takeline cin.ignore();
#define iactive cout.flush();
#define N 200005
#define endl "\n"
#define mod 1000000007
#define PI 3.141592653589793
//((1.0l)*BIG MULTIPLY MAGIC?)
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
//-----------------------------------------------
ll n,ar[N+1],st[4*N+1],ht[N+1],dp[N+1];
ll query(ll node,ll nl,ll nr,ll ql,ll qr){
	if(ql>nr||nl>qr) return 0;
	if(nl>=ql&&nr<=qr) return st[node];

	ll a,b;
	a=query(2*node,nl,(nl+nr)/2,ql,qr);
	b=query(2*node+1,(nl+nr)/2+1,nr,ql,qr);
	return max(a,b);
}
void update(ll node,ll nl,ll nr,ll idx,ll val){
	if(idx<nl||idx>nr) return ;
	if(nl==idx&&nl==nr){
		st[node]=st[node]+val;
		return ;
	}
	update(2*node,nl,(nl+nr)/2,idx,val);
	update(2*node+1,(nl+nr)/2+1,nr,idx,val);
	st[node]=max(st[2*node],st[2*node+1]);
}
int main(){

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll i,j,k,l;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>ht[i];
	}
	for(i=1;i<=n;i++){
		cin>>ar[i];
	}

	dp[1]=ar[1];
	update(1,1,N,ht[1],ar[1]);
	for(i=2;i<=n;i++){
		ll mx=query(1,1,N,0,ht[i]-1);
		dp[i]=mx+ar[i];
		update(1,1,N,ht[i],dp[i]);
	}

	ll an=0;
	for(i=1;i<=n;i++){
		an=max(an,dp[i]);
	}
	cout<<an<<endl;
	return 0;	
}