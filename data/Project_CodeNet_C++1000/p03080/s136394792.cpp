/* Dsingh_24 */

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
#define ios	    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

#define N  100005

int main()
{
	ios
	ll n,i,j,r=0,b=0;
	cin>>n;
	string s;
	cin>>s;
	for(i=0;i<n;i++)
		if(s[i]=='R')r++;
		else b++;
	if(r>b)cout<<"Yes";else cout<<"No";
	return 0;
}