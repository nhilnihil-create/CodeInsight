/* ****GT_18**** */

#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
using namespace std;

#define N  105
#define K  100005

ll n,k;
ll a[N];
ll dp[N][K];
ll pre[K];

ll solve(){
	rep(i,0,a[0]+1){
		dp[0][i]=1;
	}
	pre[0]=dp[0][0];
	rep(i,1,k+1)pre[i]=pre[i-1]+dp[0][i];
	rep(i,1,n){
		rep(j,0,k+1){
			ll mn = max(0LL,j-a[i]);
			if(mn>0){
				dp[i][j]=(pre[j]-pre[mn-1]+hell)%hell;
			}
			else{
				dp[i][j]=pre[j];
			}
		}
		pre[0]=dp[i][0];
		rep(j,1,k+1)pre[j]=(pre[j-1]+dp[i][j])%hell;
	}
	return dp[n-1][k];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
	while(TESTS--)
	{
			cin>>n>>k;
			rep(i,0,n)cin>>a[i];
			cout<<solve()<<endl;
	}
	return 0;
}