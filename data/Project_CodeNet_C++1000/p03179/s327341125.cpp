#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define owo ios_base::sync_with_stdio(0);cin.tie(0);
#define MOD (ll)(1e9+7)
#define INF (ll)(1e18)
#define debug(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false);\
debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> PII;
typedef pair<int,int> pii;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> VII;
ll gcd(ll A,ll B) {if(!B)return A;return gcd(B,A%B);}
ll dp[3001][3001];
int main()
{
	int n;
	cin>>n;
	dp[1][1] = 1;
	string s;
	cin>>s;
	for(int len=2;len<=n;len++){
			vector<ll>pref(len+1,0);
			for(int i=1;i<len;i++){
				pref[i] =dp[len-1][i]+pref[i-1];
			}		
		for(int b=1;b<=len;b++){
			if(s[len-2] == '<'){
				dp[len][b] = pref[b-1];
			}else{
			    dp[len][b] = pref[len-1]-pref[b-1];
			}
			dp[len][b]%=MOD;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++)ans+=dp[n][i];
	ans%=MOD;
	cout<<ans;
}
