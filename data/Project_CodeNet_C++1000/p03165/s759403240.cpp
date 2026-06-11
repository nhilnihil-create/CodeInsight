#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("-Ofast")
#include <bits/stdc++.h>
using namespace std;
 
typedef int in;
#define int long long
#define f first
#define s second
#define pb push_back
#define pp push
#define ceil(x) NEVER USE CEIL
#define sqrt(x) (int)(sqrt(x))
const int MAX=1e7;
const int MOD=1e9+7;
const int MAAX=1e18;

int dp[3005][3005];
string a,b;

int f(int idx1,int idx2){
	if(idx1==a.size()||idx2==b.size()){
		return dp[idx1][idx2]=0;
	}
	int &ret=dp[idx1][idx2];
	if(ret!=-1)
		return ret;
	ret=f(idx1+1,idx2);
	if(a[idx1]==b[idx2])
		ret=max(ret,f(idx1+1,idx2+1)+1);
	ret=max(ret,f(idx1,idx2+1));
	return ret;
}

in main()
{
	ios_base::sync_with_stdio(0);
    int tc=1;
    // cin>>tc;
    while(tc--)
    {
    	memset(dp,-1,sizeof dp);
		cin>>a>>b;
		f(0,0);
		string ans="";
		int idx1=0,idx2=0;
		while(idx1<a.size()&&idx2<b.size()){
			int ret=dp[idx1+1][idx2];
			ret=max(ret,dp[idx1][idx2+1]);
			if(a[idx1]==b[idx2]){
				ret=max(ret,dp[idx1+1][idx2+1]+1);
			}
			if(ret==dp[idx1+1][idx2])
				idx1++;
			else if(ret==dp[idx1][idx2+1])
				idx2++;
			else{
				ans+=a[idx1];
				idx1++;
				idx2++;
			}
		}
		cout<<ans<<endl;
    }
    return 0;
}