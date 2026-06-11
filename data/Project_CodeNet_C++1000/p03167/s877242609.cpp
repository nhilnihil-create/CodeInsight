#include<bits/stdc++.h>
#define MOD 1000000007
#define md 998244353
#define INF LLONG_MAX
#define F first
#define S second
#define sz(x) (long long)x.size()
#define vi vector<int>
#define vll vector<long long>
#define vpl vector<pair<long long,long long> >
#define vpi vector<pair<int,int> >
#define pb push_back
#define debug(x) cerr<<#x<<"= "<<x<<endl
#define all(v) v.begin(),v.end()
#define TT ll test;cin>>test; while(test--)
#define rep(i,a,n) for(ll i=a;i<(long long)n;++i)
#define repr(i,n,a) for(ll i=n;i>(long long)a;--i)
#define endl '\n'
#define MAXN 100005
typedef long long ll;
typedef long double ld;
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    ll h,w;
    cin>>h>>w;
    string s[h];
    for(int i=0;i<h;i++){
    	cin>>s[i];
	}
	ll ans=0;
	ll dp[h+1][w+1]={};
	dp[0][1] = 1;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(s[i-1][j-1] == '#'){
				dp[i][j] = 0;
			}else{
				dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
			}
		}
	}
	cout << dp[h][w];

    return 0;
}