/*
    STARK_BOY
*/
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repe(i,a,b) for(ll i=a;i<=b;i++)
#define bac(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long ll;
typedef vector< ll > vi;
typedef vector<pair<ll,ll> > vpii;
typedef pair<ll,ll> pii;
#define all(c) c.begin(),c.end()
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setbitc(x) __builtin_popcount(x)
#define init(x,a) memset(x,a,sizeof(x))
#define PI           3.14159265358979323846  /* pi */
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());


const int nax=3005;
const int MOD=1e9+7;
int dp[nax][nax];
int n;
string s;

void add_self(int &a, int b)
{
	a=(a+b)%MOD;
}

ll sub(ll a, ll b){return (a-b+MOD)%MOD;}
ll add(ll a, ll b){return (a+b)%MOD;}
ll mul(ll a, ll b){return (a*b)%MOD;}
int main()
{
    ios
    int ti=1;
    //cin>>ti;
    while(ti--)
    {
		cin>>n>>s;

		dp[1][1]=1;

		rep(pos,2,n+1)
		{
			vi pre(pos,0);
			rep(i,1,pos)pre[i]=add(pre[i-1],dp[pos-1][i]);

			rep(last,1,pos+1)
			{
				int L,R;
				if(s[pos-2]=='>')
				{
					L=last,R=pos-1;
				}
				else
				{
					L=1,R=last-1;
				}

				add_self(dp[pos][last],sub(pre[R],pre[L-1]));

			}
		}
		int ans=0;
		rep(i,1,n+1)add_self(ans,dp[n][i]);

		cout<<ans<<endl;
    }
    return 0;
        
}