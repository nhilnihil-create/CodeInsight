#include <bits/stdc++.h>
#define MAX_N (ll)23200
using namespace std;
typedef long long ll;
ll dp[1005][MAX_N+1],n;
 
struct node{
	ll w,s,v,indx;
};
node arr[100005];
bool cmp(node a,node b){
	return a.w+a.s>b.s+b.w;
}
 
ll rec(ll i,ll k){
 
	
	if(i==n+1){
		return 0;
	}
	if(dp[i][k]!=-1){
		return dp[i][k];
	}
	    ll ans=rec(i+1,k);
	    
    if(k-arr[i].w>=0){
    	ll x=min(k-arr[i].w,arr[i].s);
    	ans=max(ans,rec(i+1,x)+arr[i].v);
    }	
    
    return dp[i][k]=ans;
 
}
 
int main() {
	
	ll i,j;
	
	cin>>n;
 
	for(i=1;i<=n;i++){
			
		cin>>arr[i].w>>arr[i].s>>arr[i].v;
		arr[i].indx=i;
		
	}

	
   sort(arr+1,arr+n+1,cmp);
	
   for(i=0;i<=n;i++){
   	for(j=0;j<=MAX_N;j++){
   		dp[i][j]=-1;
   	}
   }
   
ll ans=rec(1,MAX_N);
 
cout<<ans<<endl;
	return 0;
}