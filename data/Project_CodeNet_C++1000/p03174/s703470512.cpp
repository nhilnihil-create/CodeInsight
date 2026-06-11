#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fr(i,k) for(i=0;i<k;i++)
#define ALL(c) (c).begin(),(c).end()
#define deb(x) cerr<<#x<<"  = "<<x<<endl;
#define SZ(x) (x).size();
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define em emplace_back
#define ulli unsigned long long int
#define INF 1e18
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
void solve();

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

int main() {
	fastio;
/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/

	int t;
	t=1;

    //cin>>t;
	while (t--)
	{
		solve();
	}
	return 0;
}

ll n;

ll calc(vvi &v,ll i,ll subset,vvi &dp)
{
    if(i==n)
    {
        if(subset==0)
            return 1;
        else
            return 0;
    }

    if(dp[i][subset]!=-1)
        return dp[i][subset];

    ll ans=0;
    for(ll m=0;m<n;m++)
    {
        bool f = ( (1<<m)&(subset) )?1:0;
        if( f && v[i][m]==1)
        {
            ans = (ans + calc(v,i+1,subset^(1<<m),dp))%MOD;
        }
    }

    return dp[i][subset]=ans;

}

void solve()
{
	ll i,j;
	cin>>n;

	vvi v(n,vi(n));

	for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cin>>v[i][j];
    }

    vvi dp(n,vi(1<<n,-1));

    cout<<calc(v,0,( (1<<n) - 1),dp)<<endl;

}
