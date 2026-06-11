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
#define MAXN  10000
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
	ll i,j,m,mn,q,d,x,y,ans=0,sum=0,r,p,k,c;
	string s,s1;
//	cin>>t;
	cin>>n>>k;
	ll a[n],cost[n+1];
	rep(i,0,n)cin>>a[i];
	rep(i,0,n+1)cost[i]=mod;
	cost[0]=0,cost[1]=0;
	cost[2]=abs(a[1]-a[0]);
	rep(i,2,n+1){
		rep(j,1,k+1){
			if(i>j)cost[i]=min(cost[i],cost[i-j]+abs(a[i-1]-a[i-j-1]));
		}
		
	}
//	rep(i,0,n+1)cout<<cost[i]<<" ";
cout<<cost[n];
}