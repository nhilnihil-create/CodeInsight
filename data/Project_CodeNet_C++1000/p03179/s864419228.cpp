#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
const int sz=1e5 + 5;

int n;
string s;

void add_self(int& a,int b){
	a+=b;
	if(a>=mod){
		a-=mod;
	}
	if(a<0){
		a+=mod;
	}
}

int main()
{  
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>s;
    
    vector<int> dp(n+2);
    dp[1]=1;
    for(int i=0;i<n-1;i++){
    	vector<int> new_dp(n+2);
    	int len=i+2;
    	int L=1,R=len+1;
    	for(int last=1;last<len;last++){
    		if(s[i]=='>'){
    			L=1;
    			R=last;
			}
			else{
				L=last+1;
				R=len;
			}
			add_self(new_dp[L],dp[last]);
			add_self(new_dp[R+1],-dp[last]);
		}
		int x=0;
		for(int i=1;i<=len;i++){
			add_self(x,new_dp[i]);
			dp[i]=x;
		}
	}
	
	int ans=0;
	for(int i=1;i<=n;i++){
		add_self(ans,dp[i]);
	}
	
	cout<<ans<<"\n";
}

