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
	ll n,k, i,j, ans;
	cin >> n >> k;

	ll a[n+1];

	for (i = 1; i <= n; i++)
		cin >> a[i];

	vector<vector<ll>> dp(n + 2, vector<ll>(k + 2));

	for(j=0;j<=k;j++)
        dp[1][j]=(j>a[1])?0:1;

    for(i=2;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
            if(j==0)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j] = (dp[i][j-1]+dp[i-1][j] - ( (j-a[i]-1 >=0)? dp[i-1][j-a[i]-1]:0)+MOD)%MOD;
        }
    }

    ans=dp[n][k];
	cout << ans << endl;
}
