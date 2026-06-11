//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<utility>
#include<algorithm>
#include<cstring>
#include<sstream>
#include <iomanip>

using namespace std;

typedef long long ll ;
typedef double db;
typedef vector<ll> vi;
typedef pair<int,int> pii;
typedef vector< pair<int,int> > vii;
const double pi = 2*acos(0) ;

#define pf		  	printf
#define sf			  scanf
#define pb(a)         push_back(a)
#define mp			make_pair
#define fi			 first
#define se			 second
#define for0(i,n)        for(ll i=0;i<n;i++)
#define for1(i,n)        for(int i=1;i<=n;i++)
#define forab(i,a,b)       for(int i=a;i<=b;i++)
#define lcm(a, b)     ((a)*((b)/gcd(a,b)))
#define sq(a)		   (a)*(a)
#define nw				"\n"
#define abs(x)		fabs(x)
#define pcase(z,x)    cout<<"Case "<<z<<": "<<x<<"\n"
int main()
{
	ll n;
	cin>>n;
	vi a(n),b(n),c(n);
	for0(i,n) cin>>a[i];
	for0(i,n) cin>>b[i];
	for0(i,n) cin>>c[i];
	sort(a.begin(),a.end());
	sort(c.begin(),c.end());
	ll x,y,ans=0;
	for0(i,n){
		x = lower_bound(a.begin(),a.end(),b[i])-a.begin();
		y = upper_bound(c.begin(),c.end(),b[i]) - c.begin();
		//cout<<x<<" "<<y<<nw;
		ans += (x)*(n-y);
		}
	cout<<ans<<nw;
	
	return 0;
}