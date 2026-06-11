#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll mod=1000000007;
const char nl='\n';


void solve(){
    ll i,j,k,l,m,n;
    string s,t;
    cin>>s>>t;
    n=(ll)s.size();
    m=(ll)t.size();
    vector<vector<int> > dp(n+1, vector<int>(m+1,0));
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            dp[i][j]= max({dp[i][j-1],dp[i-1][j], (int)(s[i-1]==t[j-1])+dp[i-1][j-1]});
        }
    }

//    for(auto x:dp){
//        for(auto y:x) cout<<y<<" ";cout<<nl;
//    }
    string ans="";
    i=n;
    for(j=m;j&&i;j--){
        if(dp[i][j]==dp[i][j-1]) continue;
        if(dp[i][j]==dp[i-1][j]) i--,j++;
        else if(dp[i-1][j-1]+1==dp[i][j]){
            ans+=t[j-1];
            i--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<nl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1,i=1;
//    cin >> t;
	while (t--)
	{
//	    cout<<"Case #"<< i++ <<": ";
		solve();
	}
	return 0;
}

