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
	int L,z;vector<vector<int> > v;
	cin>>L;
	repb(i,1,18)v.pb({i,i+1,1<<(i-1)}),v.pb({i,i+1,0});
	z=0;
	lepb(i,19,1)
	{
		while(L>=(1<<(i-1)))
		{
			v.pb({i,20,z});
			z+=1<<(i-1);L-=1<<(i-1);
		}
	}
	cout<<20<<" "<<sz(v)<<endl;
	for(auto t:v)cout<<t[0]<<" "<<t[1]<<" "<<t[2]<<endl;
}