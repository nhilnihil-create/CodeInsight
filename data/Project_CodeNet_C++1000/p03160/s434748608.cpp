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

//syntax for priority queue
// max queue -> priority_queue<ll>
// min queue -> priority_queue<ll,vector<ll>,greater<ll>>

//##############################################################################################

ll getRes(ll arr[], ll n)
{
    ll dp[n+ 1] = { 0 };
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = abs(arr[1] - arr[0]);
    for (ll i = 3; i <= n; i++)
    {
        dp[i] = min(dp[i - 1] + abs(arr[i - 1] - arr[i - 2]), dp[i - 2] + abs(arr[i - 1] - arr[i - 3]));
    }

    return dp[n];
}

void solve()
{
    ll n;
    cin >> n;
    ll arr[100001];
    f(i, n)
        cin >> arr[i];
    if (n < 2)
    {
        cout << 0 << "\n";
        return;
    }
    //cout << n << " ";
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