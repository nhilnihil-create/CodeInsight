#include<bits/stdc++.h>
#define FOR(i,a,b)for(int i=(a),_b=(b);i<=_b;i++)
#define FORN(i,b,a)for(int i=(b);_a=(a);i>=_a;i--)
#define REP(i,n)for(int i=0,_n=n;i<n;i++)
#define ll long long
#define pii pair<int,int>
#define re return
#define vi vector<int>
#define pb push_back
#define si set<int>
#define in insert
#define fl float
#define db double
#define ld long double
#define X first
#define Y second
#define st string
#define ull unsigned long long
#define mod 1000000007
#define INF 1000000007
using namespace std;
inline void read(int &x)
{
	short negative=1;
    x=0;
    char c=getchar();
    while(c<'0' || c>'9')
    {
		if(c=='-')
			negative=-1;
		c=getchar();
	}
    while(c>='0' && c<='9')
        x=(x<<3)+(x<<1)+(c^48),c=getchar();
    x*=negative;
}
int main()
{
	vector<ll>v;
	ll a[100100],b[100100];
	int n;
	cin>>n;
	REP(i,n)cin>>a[i];
	REP(i,n)cin>>b[i];
	ll cnt1=0,cnt2=0;
	ll sum=0;
	ll ans=0;
	REP(i,n)
	{
		if(a[i]>b[i])v.pb(a[i]-b[i]);
		if(a[i]<b[i]){ans++;
		sum+=b[i]-a[i];
		}
		cnt1+=a[i];
		cnt2+=b[i];
	}
	if(cnt1<cnt2){
		cout<<-1<<endl;
		return 0;
	}
	sort(v.rbegin(),v.rend());
	REP(i,v.size())
	{
		if(sum>0)
		{
			sum-=v[i];
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

