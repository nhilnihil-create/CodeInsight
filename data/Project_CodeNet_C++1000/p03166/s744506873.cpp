// Take care of mod becoming -ve

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define fro(i, s, e) for (auto i = s; i <= e; ++i)
#define int long long
#define ld long double
#define fr(i, n) for (auto i = 0; i < n; i++)
#define ff first
#define pf pop_front()
#define ss second
#define mp make_pair
#define vi std::vector<int>
#define pii pair<int, int>
#define mii map<int, int>
#define setbits(x) __builtin_popcountll(x)
#define zrbits(x) __builtin_ctzll(x)
#define vii std::vector<int, int>
#define tc    \
    int t;    \
    cin >> t; \
    while (t--)
#define FILE                          \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define inp(a) \
    int a;     \
    cin >> a;
#define ps(x, y) fixed << setprecision(y) << x
#define mkarr(arr, n, type) type *arr = new type[n];
#define endl "\n"
#define rev(i, e, s) for (auto i = e; i >= s; --i)
const int mod = 1000000007;
#define min_pq priority_queue<int, std::vector<int>, greater<int>>
#define printclock cerr << "Time : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC << "ms\n";
using namespace std;
const int N = 100005;
const int inf = 1000000000000000000;
#define fit(s, x) memset(s, x, sizeof(s));
#define out(x) cout << x << "\n"
#define deb(x) cout << #x << x << "\n"
#define pi 3.14159265358979323846264338327950
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    PBDS;
// Use __gcd(a,b) for gcd
// find(all(x),key) to get the iterator and its index is obtained by find(all(x),key)-x.begin()
// find_if(iterator_first,iterator_last,unary function) returns first iterator if any element corresponding to unary function exists and if no such element is found it retrurns the last iterator
/*For example:
find_if(all(x),isodd) for x being a vector{10,25,40,55}; *it returns 25*/
/*search(all(v1),all(v2),pred) searches for all the elements of v2 present in v1 based on pred function the iterator correspond
to the first element of sequence if it exists and if not then th elast iterator is obtained.*/
//use substr(size_t pos,size_t len) for the substrings
// iota(forward itr,backwrd itr,val) can be used for consecutive numbers
int power(int a, int b)
{
    long long ans = 1;
    while (b > 0)
    {
        if (b & 1LL)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b = (b >> 1LL);
    }
    return ans;
}
int a[2 * N];
int n,k;
string s, t;
int dp[N];
vector<vi>graph(N);
int solve(int i){
    if(dp[i]!=-1)
        return dp[i];
    
    int ans(0);
    for(auto nbr:graph[i]){
        ans=max(ans,1+solve(nbr));
    }
    return dp[i]=ans;
}
int32_t main()
{
    fio;
    // indexed_set s;
    // s.insert(2);
    // auto y = s.find_by_order(7);
    // cout << *x << " " << *y <<
    int m;
    cin>>n>>m;
    memset(dp,-1,sizeof(dp));
    fr(i,m){
        int x,y;
        cin>>x>>y;
        graph[x].pb(y);
    }
    int ans(0);
    for(int i=1;i<=n;i++){
        if(dp[i]!=-1){
            ans=max(ans,dp[i]);
        }
        else{
            ans=max(ans,solve(i));
        }
    }
    out(ans);
    printclock;
    return 0;
}
