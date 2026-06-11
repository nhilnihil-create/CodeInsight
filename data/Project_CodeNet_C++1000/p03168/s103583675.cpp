#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define INF 1'000'000'007
#define cases int t;cin>>t;while(t--)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,a,b) for(ll i=a;i>=b;i--)
#define ff first
#define ss second

#define test4(x,y,z,a) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<"		a is "<<a<<endl;
#define test3(x,y,z) cout<<"x is "<<x<<"		y is "<<y<<"		z is "<<z<<endl;
#define test2(x,y) cout<<"x is "<<x<<"		y is "<<y<<endl;
#define test1(x) cout<<"x is "<<x<<endl;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	ll n;
	cin>>n;
	double p[n];
	rep(i,0,n){
		cin>>p[i];
	}
	double dp[n+1][n+1];
	dp[0][0]=1;
	rep(i,0,n+1){
		rep(j,0,n+1){
			if(i==0&&j==0)
				continue;
			if(i==0){
				dp[i][j]=0;
			}
			else if(j==0){
				dp[i][j]=dp[i-1][j]*(1-p[i-1]);
			}
			else if(i>j){
				dp[i][j]=dp[i-1][j-1]*p[i-1]+dp[i-1][j]*(1-p[i-1]);
			}
			else if(i==j){
				dp[i][j]=dp[i-1][j-1]*p[i-1];
			}
		}
	}
	double x=0;
	rep(i,(n+1)/2,n+1){
		x+=dp[n][i];
	}
	cout<<setprecision(12)<<fixed<<x;
	
	
	
	return 0;
}