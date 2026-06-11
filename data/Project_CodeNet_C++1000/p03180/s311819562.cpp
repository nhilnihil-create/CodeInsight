#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
const int sz=18;

int n;
ll a[sz][sz];

void add_self(ll& a,ll b){
	a+=b;
}
void max_self(ll& a,ll b){
	a=max(a,b);
}

int main()
{  
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cin>>a[i][j];
		}
	}
	
	vector<ll> pre(1<<n);
	
    for(int mask=0;mask<(1<<n);mask++){
    	for(int i=0;i<n;i++){
    		if(mask&(1<<i)){
    			for(int j=i+1;j<n;j++){
    				if(mask&(1<<j)){
    					add_self(pre[mask],a[i][j]);
					}
				}
			}
		}
    }
	
	
	vector<ll> dp(1<<n);
	for(int mask=0;mask<(1<<n);mask++){
		vector<ll> not_taken;
		for(int i=0;i<n;i++){
			if(!(mask&(1<<i))){
				not_taken.push_back(i);
			}
		}
		int len=not_taken.size();
		for(int msk=0;msk<(1<<len);msk++){
			int group=0;
			for(int j=0;j<len;j++){
				if(msk&(1<<j)){
					group=group|(1<<not_taken[j]);
				}
			}
			max_self(dp[mask|group],dp[mask]+pre[group]);
		}
	}

   cout<<dp[(1<<n)-1]<<"\n";
    
}

