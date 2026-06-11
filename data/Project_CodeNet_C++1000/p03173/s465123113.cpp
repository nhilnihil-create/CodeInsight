//******* It's LEVI_17 ***************

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define ff first
#define ss second
#define MP make_pair
#define mset(x,a) memset(x,a,sizeof(x))
#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))
#define sqr(a) (a)*(a)
#define all(x) (x).begin(), (x).end()
#define f(i, n) for (int i = 0; i < n; i++)
#define f1(i, n) for (int i = 1; i <= n; i++)
#define loop(i,a,b) for (int i = a; i < b; i++)
#define bloop(i,a,b) for (int i = a ; i>=b;i--)
#define vvll vector<vector<ll>>  
#define vll vector<ll> 
#define pll pair<ll,ll>
#define vpll vector<pll>
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define cases ll t;cin >> t;while(t--)
#define rr return 0
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define deb(a)			std::cerr<<#a<<"="<<(a)<<"\n"
#define deb2(a,b)		std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
#define deb3(a,b,c)		std::cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
const int MOD = 1000 * 1000 * 1000 + 7;
const ll INF = 1e18L + 5;
//syntax for priority queue
// max queue -> priority_queue<ll>
// min queue -> priority_queue<ll,vector<ll>,greater<ll>>

//##############################################################################################

ll sum(ll arr[], ll L, ll R)
{
    ll s = 0;
    for (ll i = L; i <= R; i++)
        s += arr[i];
    return s;
}
ll getRes(ll arr[], ll n)
{
    ll dp[405][405];
    // dp[i][j] -> minimum total cost of combining interval [i,j] into one vertex

    for (ll L = n - 1; L >= 0; L--)
    {
        for (ll R = L; R < n; R++)
        {
            if (L == R)
                dp[L][R] = 0;
            else
            {
                dp[L][R] = INF;
                ll s = sum(arr,L, R);

                for (ll i = L; i <= R - 1; i++)
                {
                    dp[L][R] = min(dp[L][R], dp[L][i] + dp[i + 1][R] + s);
                }
            }
        }
    }
    

    return dp[0][n - 1];
}

void solve()
{
    ll n;
    cin >> n;
    ll arr[405];
    f(i, n)
        cin >> arr[i];

    ll res = getRes(arr, n);

    cout << res << "\n";
}

//###############################################################################################

int main()
{
    fast;
    ll t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    rr;
}


//Watashi wa tsuyoku modotte kimasu