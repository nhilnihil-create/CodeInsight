#include<bits/stdc++.h>
using namespace std;
#define ar array
#define endl '\n'
#define ll long long
#define in insert
#define pb push_back
#define vt vector
#define P_Q(x) priority_queue<x>
#define p_q(x) priority_queue<x, vector<x>, greater<x>>
#define Rep(i,a,b) for(int i=a;i<=b;i++)
#define Rev(i,a,b) for(ll i=a;i>=b;i--)
#define FOR(m) Rep(i,1,m)
#define For(m) Rep(i,0,m-1)
#define Rbl(x,a) for(auto &x : a)
#define FIO ios::sync_with_stdio(0);   cin.tie(0);
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define vpii vector<pii>
#define vpll vector<pll>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()
const ll INF = 0x3f3f3f3f3f3f3f3fll;
#define mod 1000000007
 
const int mxN = 1e5 + 1;
vt<ll> dp(mxN), pfx(mxN, 1);
ll n, k;
 
 
int main()
{
FIO
 
    cin >> n >> k;
    ll num;
    For(n)
    {
        cin >> num;
        Rev(s,k,0)
        {
            ll l = max(s - num, 0ll);
            ll r = s;
            dp[s] = mod + pfx[r] - (l == 0 ? 0 : pfx[l-1]);
            dp[s] %= mod;
        }
        Rep(s,0,k)
        {
            pfx[s] = dp[s] + (s == 0 ? 0 : pfx[s-1]); 
            pfx[s] %= mod;
        }
    }
    cout << dp[k] << endl;
}