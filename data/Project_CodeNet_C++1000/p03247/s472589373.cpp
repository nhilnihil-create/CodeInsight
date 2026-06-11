#include<bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for(int i=(s);i<(t);++i)
#define per(i,s,t) for(int i=((t)-1);i>=s;--i)
#define repb(i,s,t) for(int i=(s);i<=(t);++i)
#define lepb(i,s,t) for(int i=(s);i>=(t);--i)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)x.size())
#define mst(a,b) memset(a,b,sizeof(a))
#define dd(x) cout<<#x<<'='<<x<<' '
#define de(x) cout<<#x<<'='<<x<<'\n'
#define fi first
#define se second
#define sq(x) ((x)*(x))
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;

const int inf = 0x3f3f3f3f;
const ll inff = 4557430888798830399ll;
const db eps = 1e-10;
const db pi = acos(-1.0);
const ll mod = 1e9+7;

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,x[2000],y[2000];vector<int> v;string c;
	cin>>n;
	rep(i,0,n)cin>>x[i]>>y[i];
	rep(i,1,n)if((abs(x[i])+abs(y[i]))%2!=(abs(x[0])+abs(y[0]))%2)
	{
		cout<<-1<<endl;return 0;
	}
	if((abs(x[0])+abs(y[0]))%2==0)v.pb(1);
	repb(i,0,30)v.pb(1<<i);reverse(all(v));
	cout<<sz(v)<<endl;rep(i,0,sz(v))cout<<v[i]<<" ";cout<<endl;
	rep(i,0,n)
	{
		c.clear();
		rep(j,0,sz(v))
		{
			if(abs(x[i])>abs(y[i]))
			{
				if(x[i]>0){x[i]-=v[j];c+="R";}
				else {x[i]+=v[j];c+="L";}
			}
			else
			{
				if(y[i]>0){y[i]-=v[j];c+="U";;}
				else {y[i]+=v[j];c+="D";;}
			}
		}
		cout<<c<<endl;
	/*	int tx=0,ty=0;
		rep(j,0,sz(v))
		{
			if(c[j]=='R')tx+=v[j];
			if(c[j]=='L')tx-=v[j];
			if(c[j]=='U')ty+=v[j];
			if(c[j]=='D')ty-=v[j];
		}
		dd(tx);de(ty);*/
	}
}