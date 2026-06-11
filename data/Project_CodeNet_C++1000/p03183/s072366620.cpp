#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define mod 1000000007
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
const int sz=18;

int n;
int w_max = 21322;



struct S{
    int w,s;
    ll v;
    
    void read(){
        cin>>w>>s>>v;
    }
};

bool cmp(S a,S b){
    return (a.w + a.s) < (b.w + b.s);
}


int main()
{  
    ios::sync_with_stdio(false);   
    cin.tie(0);
    
    cin>>n;
    vector<S> v(n);
    for(int i=0;i<n;i++){
    	v[i].read();
	}
    
    sort(v.begin(),v.end(),cmp);
    
    //dp(j) = with j weights, what is max value
    vector<ll> dp(w_max+1);
    for(int i=0;i<n;i++){
    	for(int j=min(v[i].s,w_max-v[i].w);j>=0;j--){
    		dp[j+v[i].w]=max(dp[j+v[i].w],dp[j]+v[i].v);
		}
	}
	ll ans=0;
	for(int i=0;i<=w_max;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans<<"\n";
}

