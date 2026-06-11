#include <bits/stdc++.h>
using namespace std;
/*---define tricks---*/
#define ALL(v) v.begin(),v.end()
#define UN(v) sort(ALL(v)),v.erase(unique(ALL(v)),v.end())
#define FILL(x,y) memset(x,y,sizeof(x))
#define EACH(v,it) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define FIO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define revsort(b,e) sort(b,e),reverse(b,e)
/*---define types---*/
typedef long long ll;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
/*---define variables---*/
int n;
bool f[200005];
ll a[200005],b[200005],c[200005],d[200005],ans;
/*---define function---*/

/*---main code---*/
int main()
{
	FIO;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;++i)
	{
		cin>>b[i];
	}
	for(int i=0;i<=30;++i)
	{
		ll T=((ll)1<<i);
		for(int j=0;j<n;++j)
		{
			c[j]=a[j]%(2*T);
			d[j]=b[j]%(2*T);
		}
		sort(d,d+n);
		for(int j=0;j<n;++j)
		{
			ll y=2*T-c[j];
			ll x=T-c[j];
			int p1=lower_bound(d,d+n,x)-d;
			int p2=lower_bound(d,d+n,y)-d;
			if(d[p2]>=y)
			{
				--p2;
			}
			if(p2>=n)
			{
				--p2;
			}
//			cout<<p1<<' '<<p2<<"		";
			if(p2>=p1&&(p2-p1+1)%2)
			{
				f[i]=!f[i];
			}
			y=4*T-c[j];
			x=3*T-c[j];
			p1=lower_bound(d,d+n,x)-d;
			p2=lower_bound(d,d+n,y)-d;
			if(d[p2]>=y)
			{
				--p2;
			}
			if(p2>=n)
			{
				--p2;
			}
//			cout<<p1<<' '<<p2<<'\n';
			if(p2>=p1&&(p2-p1+1)%2)
			{
				f[i]=!f[i];
			}
		}
	}
	for(int i=0;i<=30;++i)
	{
		if(f[i])
		{
			ans|=((ll)1<<i);
		}
	}
	cout<<ans<<'\n';
	return 0;
}
