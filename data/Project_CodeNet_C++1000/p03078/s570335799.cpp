#include<bits/stdc++.h>
#define ll long long
#define REP(i,a,n) for(ll i=a;i<(n);i++)
#define REP_sz(i,s) for(ll i=0;i<s.size();i++)
#define RE return
#define FILL(a,b) memset(a,b,sizeof(a))
#define SO(a) sort(all(a))
#define pb push_back
#define sz(a) a.size()
#define V vector
#define ld long double
#define viit(a) vector<int>::iterator a
#define msit1(a) map<string,int>::iterator a
#define miit(a) map<int,int>::iterator a
#define msit2(a) map<int,string>::iterator a
#define IT iterator
#define FOR(i,a,n) for(ll i=a;i<=(n);i++)
#define B(s) s.back()
#define all(a) a.begin(),a.end()
#define ER1(a) a.erase(a.begin())
#define ER0(a) a.erase(a.end())
#define pii pair<int,int>
#define pause system("PAUSE")
#define cls system("CLS")
using namespace std;
ll _min(int a,ll b){
	return a<b?a:b;
}
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	V<ll>a,b,c,ab,abc;
	ll x,y,z,K;
	cin>>x>>y>>z>>K;
	REP(i,0,x){
		ll x;
		cin>>x;
		a.pb(x);
	}
	REP(i,0,y){
		ll x;
		cin>>x;
		b.pb(x);
	}
	REP(i,0,z){
		ll x;
		cin>>x;
		c.pb(x);
	}
	SO(a);SO(b);SO(c);
	REP(i,0,x)
	REP(j,0,y)
	ab.pb(a[i]+b[j]);
	sort(all(ab),greater<ll>());
	//cout<<ab[0]<<endl;
	for(ll i=0;i<_min(ab.size(),K);i++)
	REP(j,0,z)
	abc.pb(ab[i]+c[j]);
	sort(all(abc),greater<ll>());
	for(int i=0;i<K;i++)cout<<abc[i]<<endl;
    return 0;
}
