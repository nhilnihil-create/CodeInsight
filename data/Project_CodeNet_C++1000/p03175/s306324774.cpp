#include"bits/stdc++.h"
using namespace std;

#define ll long long int
#define f(i,x,n)  for(int i=x;i<n;i++)
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define sz(a) int((a).size())
#define mod 1000000007
#define inf LLONG_MAX
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
template <typename T>
inline T gcd(T a, T b)
{
    while (b != 0) swap(b, a %= b);
    return a;
}

template <typename T>
inline void seethis(vector<T>vect)
{
    for(T x : vect)
        cout << x << " ";
    cout << "\n";
}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
//LCM
int lcm(int a, int b)
{
    return a * (b / gcd(a, b));
}

//For sort by second
bool cmp(const pair<int, int> &a)
{
    return a.first < a.second;
}

const int MAXN = 1e5 + 5;
vector<ll> adj[MAXN];

//ModPower
ll modpower(ll a, ll b, ll c)
{
    ll res = 1;
    while(b)
    {
        if(b & 1LL)
            res = (res * a) % c;
        a = (a * a) % c;
        b >>= 1;
    }
    return res;
}
ll n;

ll dp[MAXN][2];


void mul(ll &a, ll b)
{
    a *= b;

    if(a >= mod)
        a -= mod;

}

void add_self(ll &a, ll b)
{
    a += b;

    if(a >= mod)
        a -= mod;
}

ll solve(ll u, ll par, int color)
{
    if(dp[u][color] != 0)
        return dp[u][color];

    ll res = 0;
    //I i am coloring the current node white:
    ll ways1 = 1;
    for(ll child : adj[u])
    {

        if(child != par)
        {
            ways1 =  (ways1 * solve(child, u, 0)) % mod;
        }

    }
    add_self(res, ways1);

    //I am coloring the current node black only if parent is white

    if(color == 0)
    {
        ll ways2 = 1;
        for(ll child : adj[u])
        {
            if(child != par)
            {
                ways2 =  (ways2 * solve(child, u, 1)) % mod;
            }
        }
        add_self(res, ways2);
    }


    return dp[u][color] = res;
}


int main()
{
    FASTIO;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> n;

    for(ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(dp, sizeof dp, 0);
    cout << solve(1, -1, 0) << "\n";
    return 0;
}