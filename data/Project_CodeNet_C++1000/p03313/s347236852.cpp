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
ll p[1<<19],q[1<<19];
int main()
{
	ios
	ll n,i,j;
	cin>>n;
	ll a[(1<<18)+1];
	for(i=0;i<(1<<n);i++){
		cin>>a[i];
		p[i]=a[i],q[i]=0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<(1<<n);j++){
			if(j&(1<<i)){
				ll x[4];
				x[0]=p[j],x[1]=q[j],x[2]=p[j^(1<<i)],x[3]=q[j^(1<<i)];
				sort(x,x+4);
				p[j]=x[3],q[j]=x[2];
			}
		}
	}
	ll ans=0;
	for(i=1;i<(1<<n);i++){
		ans=max(ans,p[i]+q[i]);
		cout<<ans<<"\n";
	}
	return 0;
}