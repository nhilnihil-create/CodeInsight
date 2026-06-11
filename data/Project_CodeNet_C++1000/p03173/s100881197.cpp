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
 
const int mxN = 400 + 1;
vt<ll> a;
ll dp[mxN][mxN];
ll n;
 
 
int main()
{
FIO
 
    cin >> n;
    a = vt<ll>(n);
    For(n) 
    {
        cin >> a[i];
    }

    Rev(i,n-1,0)
    {
        dp[i][i] = 0;
        ll sum = a[i];
        Rep(j,i+1,n-1)
        {
            sum += a[j];
            dp[i][j] = INF;
            Rep(k,i,j-1)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum);
            }
        }
    }

    cout << dp[0][n-1] << endl;

    return 0;
}