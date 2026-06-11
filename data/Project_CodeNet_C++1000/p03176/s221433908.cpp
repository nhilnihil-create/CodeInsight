#include <bits/stdc++.h>
using namespace std;
struct flower
{
    long long int hi,bty;
};
long long int solve(vector<flower> &v,long long int n)
{
    vector<long long int> dp(n+1);
    dp[1]=v[1].bty;
    map<long long int,long long int> meaningfull;
    meaningfull[v[1].hi]=v[1].bty;
    long long int ans=dp[1];
    for(int i=2;i<=n;i++)
    {
        dp[i]=v[i].bty;
        auto it=meaningfull.lower_bound(v[i].hi);
        if(it!=meaningfull.begin())
        {
            it--;
            dp[i]+=it->second;
        }
        meaningfull[v[i].hi]=dp[i];
       
        it=meaningfull.upper_bound(v[i].hi);
        
        
        while(it!=meaningfull.end()&&it->second<=dp[i])
        {
            auto temp=it;
            temp++;
            meaningfull.erase(it);
            it=temp;
        }
        ans=max(ans,dp[i]);
    }
    return ans;
}
int main() {
	long long  int n;
	cin>>n;
	vector<flower> v(n+1);
	
	for(int i=1;i<=n;i++)
	{
	    cin>>v[i].hi;
	}
	for(int i=1;i<=n;i++)
	{
	    cin>>v[i].bty;
	}
	long long int ans=solve(v,n);
	cout<<ans<<endl;
	return 0;
}