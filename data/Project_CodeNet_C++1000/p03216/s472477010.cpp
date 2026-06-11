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
	int n,q,k,d,M,C;string s;ll S,Z;
	cin>>n>>s>>q;
	rep(i,0,q)
	{
		cin>>k;
		d=s.find_first_of('D');S=Z=M=C=0;
		if(d==-1){cout<<0<<endl;continue;}
		for(int i=d,j=d;i<sz(s);i++)
		{
			if(s[i]=='D')
			{
				for(;j-i<k&&j<sz(s);j++)
				{
					if(s[j]=='M')M+=1;
					if(s[j]=='C')Z+=M,C+=1;
				}
				S+=Z;
			}
			if(s[i]=='M')Z-=C,M-=1;
			if(s[i]=='C')C-=1;
		}
		cout<<S<<endl;
	}
}