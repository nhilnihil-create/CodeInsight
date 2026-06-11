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

void solve()
{
	ll n,i,j,k,c,ans=0;
	cin>>n;

	ll a[n];

	for(i=0;i<n;i++)
        cin>>a[i];

    vector<vector<ll>> dp(n,vector<ll>(n,INF));
    vector<vector<ll>> sum(n,vector<ll>(n));

    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(i==j)
                sum[i][j]=a[j];
            else
                sum[i][j]=sum[i][j-1]+a[j];
        }
    }

    for(i=0;i<n;i++)
        dp[i][i]=0;

    for(c=1;c<n;c++)
    {
        i=0;
        j=c;
        while(j<n)
        {
            for(k=i;k<j;k++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[i][j]);
            }

            j++;
            i++;
        }
    }

    ans=dp[0][n-1];
    cout<<ans<<endl;
}
