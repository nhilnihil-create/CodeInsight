#include<bits/stdc++.h>
#define ll long long 
#define mp make_pair 
#define f(i,n) for(int i=0;i<n;i++) 
#define F first 
#define S second 
#define pb push_back 

using namespace std;

ll cache[100005];

ll dp(ll a[],ll n,ll k){
	if(n<=0)
		return 0;
	if(n==1)
		return abs(a[1]-a[0]);
	if(cache[n]!=-1)
		return cache[n];
	ll &ans = cache[n];
	
	ans = abs(a[n]-a[n-1]) + dp(a,n-1,k);
	
	for(int i=1;i<=k;i++){
		if(n-i>=0)
			ans = min(ans,abs(a[n]-a[n-i]) + dp(a,n-i,k));
	}
	return ans;
	
}

void test(){
	ll n,k;
	cin>>n>>k;
	ll a[n];
	f(i,n)cin>>a[i];
	reverse(a,a+n);
	
	memset(cache,-1,sizeof(cache));
	
	cout<<dp(a,n-1,k);
	
	
}

int main(){
	int tests=1;
	// cin>>tests;
	while(tests--){
		test();
	}
}
