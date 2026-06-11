#include <bits/stdc++.h>
#define IOS   ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define mp    make_pair
#define pb    push_back
#define F     first
#define pi 	  3.14159265358979323846
#define S     second
#define ll    long long
#define ld    long double
#define sz(s) (ll)s.size() 
#define vl    vector < ll >
#define pll   pair < ll, ll >
#define ml    map < ll, ll >
#define mod   1000000007
#define qe	  998244353
#define MAXN  100005
#define mx    10000005
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define inv(i,a,b)  for(i=a;i>=b;i--)
#define all(a)  (a).begin(),(a).end()
using namespace std;
int main(){
//	#ifndef ONLINE_JUDGE
//    if (fopen("input.txt", "r"))
//    {
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//    }
//	#endif
	IOS;
	ll t,n,l,l1;
	ll i,j,m,mn,q,d,x,y,sum=0,r,p,k,c;
	string s,s1;
	cin>>n>>k;
	ll a[n],dp[k+1]={0};
	rep(i,0,n)cin>>a[i];
	rep(i,1,k+1){
		rep(j,0,n){
			ll z=1;
			if(a[j]<=i){
				z^=dp[i-a[j]];
			dp[i]|=z;
			}
		}
	}
//	rep(i,0,k+1)cout<<dp[i]<<" ";
	if(dp[k])cout<<"First";else cout<<"Second";
}