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
ll dp[K][2];
ll a[N];

ll solve(){
	// cout<<left<<" "<<turn<<endl;
	// if(dp[left][turn]!=-1){cout<<"HI";return dp[left][turn];};
	// bool ans=0;
	// rep(i,0,n){
	// 	if(left-a[i]<0)continue;
	// 	if(solve(left-a[i],1-turn)==0){ans=1;break;}
	// }
	// return dp[left][turn]=ans;

	rep(i,0,k+1){
		rep(j,0,2){
			rep(l,0,n){
				if(i-a[l]<0)continue;
				if(dp[i-a[l]][1-j]==0){dp[i][j]=1;break;}
			}
		}
	}
	return dp[k][0];

}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
	// rep(i,0,K)dp[i][0]=dp[i][1]=-1;
	while(TESTS--)
	{
		cin>>n>>k;
		rep(i,0,n)cin>>a[i];
		bool win = solve();
		if(win){
			cout<<"First"<<endl;
		}
		else cout<<"Second"<<endl;
	}
	return 0;
}