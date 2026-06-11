/*"Everything in the universe is balanced. Every disappointment
   you face in life will be balanced by something good for you!
                Keep going, never give up."            */

#include "bits/stdc++.h"
using namespace std;

#define ll long long
const ll N=1e6+9;
const ll mod=1e9+7;

ll a[N];

void solve()
{    
    ll n, m ,W;
    string s,t;
    cin >> s >> t;
    n = s.size() ;
    m = t.size() ;

    vector<vector<int>> dp(n+1, vector<int>(m+1,0)) ;
    for(int i = 1; i<=n; i++){
    	for(int j=1; j<=m; j++){
    			if(s[i-1]==t[j-1]) {
    				dp[i][j] = dp[i-1][j-1]+1;
    			}
    			else dp[i][j] = max(dp[i-1][j],dp[i][j-1]) ;
    			//cout<<dp[i][j]<<" ";
    	}
    	//cout<<"\n";
    }

    string ans = "" ;
/*ll r=n,c=m;
	while(1)
	{
		if(s[r-1]==t[c-1])
		{
			ss+=s[r-1];
			r--;
			c--;
		}
		else
		{
			if(a[r-1][c]>a[r][c-1])
			{
				r--;
			}
			else c--;
		}
		//cout<<r<<" "<<c<<" "<<ss<<nl;
		if(r<1 || c<1)break;
	}*/

    int total = dp[n][m] ,i=n ,j=m;

    while(i&&j) {
    	if(s[i-1]==t[j-1]){
    		ans += s[i-1] ;
    		i--;j--;total--;
    	}
    	else {
    		if(dp[i-1][j]>dp[i][j-1])i--;
    		else j--;
    	}
    }
    reverse(ans.begin(),ans.end());
    cout<< ans; 

}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t=1;
    //pre();
    //cin>>t;
    while(t--)
    {
      solve();
    }  
}


// Xorawar