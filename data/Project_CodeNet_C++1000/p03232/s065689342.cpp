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

ll fpow(ll b,ll p){ll r=1;for(;p;p>>=1,(b*=b)%=mod)if(p&1)(r*=b)%=mod;return r;}

#define maxn 100005
ll A[maxn],F[maxn],S;int n;

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	S=0;mst(F,0);mst(A,0);
	cin>>n;
	repb(i,1,n)cin>>A[i];
	repb(i,1,n)F[i]=fpow(i,mod-2);
	repb(i,1,n)(F[i]+=F[i-1])%=mod;
	repb(i,1,n)(S+=A[i]*(F[i]+F[n-i+1]-F[1]))%=mod;
	repb(i,1,n)(S*=i)%=mod;
	cout<<S<<endl;
}