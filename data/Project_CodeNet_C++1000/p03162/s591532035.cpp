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

ll getRes(ll arr[],ll brr[],ll crr[], ll n)
{
    ll dp[n + 1][3];
    dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
    for (ll i = 1; i <= n; i++)
    {
        dp[i][0] = arr[i - 1] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = brr[i - 1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = crr[i - 1] + max(dp[i - 1][0], dp[i - 1][1]);
    }

    return max(dp[n][0], max(dp[n][1], dp[n][2]));

}

void solve()
{
    ll n;
    cin >> n;
    ll arr[n], brr[n], crr[n];
    f(i, n)
        cin >> arr[i] >> brr[i] >> crr[i];
   
    ll res = getRes(arr,brr,crr, n);
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