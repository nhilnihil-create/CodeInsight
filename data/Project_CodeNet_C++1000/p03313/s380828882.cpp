#include<bits/stdc++.h>
using namespace std;
#define sz(x) int(x.size())
#define pb push_back
#define ff first
#define ss second
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,ii> qu;

qu op(qu a,qu b){
	set<ii>g;
	g.insert(a.ff);g.insert(a.ss);
	g.insert(b.ff);g.insert(b.ss);
	vector<ii>vec;
	for(ii s: g)vec.pb(s);
	return qu(vec[sz(vec)-1],vec[sz(vec)-2]);
}

int main(){
	int n;cin>>n;
	int lim=1<<n;
	qu neutro={{-1,-1},{-1,-1}};
	vector<qu>dp(lim);
	for(int i=0;i<lim;i++){
		dp[i]=neutro;
		cin>>dp[i].ff.ff;
		dp[i].ff.ss=i;
		dp[i].ss.ss=i;
	}
	for(int i=0;i<lim;i++){
		//cout<<"i "<<i<<endl;
		for(int j=0;j<n;j++)if(((i>>j)&1)==0){
			int see=i|(1<<j);
			dp[see]=op(dp[see],dp[i]);
		}
		//cout<<dp[i].ff<<" "<<dp[i].ss<<endl;
	}
	int ans=0;
	for(int i=1;i<lim;i++){
		ans=max(ans,dp[i].ff.ff+dp[i].ss.ff);
		cout<<ans<<endl;
	}
	return 0;
}
