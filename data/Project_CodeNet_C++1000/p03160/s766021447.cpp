#include<bits/stdc++.h>
#define ll long long 
#define mp make_pair 
#define f(i,n) for(int i=0;i<n;i++) 
#define F first 
#define S second 
#define pb push_back 

using namespace std;



void test(){
	int n;
	cin>>n;
	ll a[n];
	f(i,n)cin>>a[i];
	reverse(a,a+n);
	
	ll dp[n];
	dp[0] = 0;
	dp[1] = abs(a[1]-a[0]);
	
	for(int i=2;i<n;i++){
		dp[i] = min(abs(a[i]-a[i-1])+dp[i-1],abs(a[i]-a[i-2])+dp[i-2]);
	}
	cout<<dp[n-1]<<"\n";
}

int main(){
	int tests=1;
	// cin>>tests;
	while(tests--){
		test();
	}
}
