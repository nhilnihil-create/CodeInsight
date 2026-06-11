// be name khoda
#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
//#define mp make_pair 
typedef long long ll;
#define int long long
#pragma GCC optimize("Ofast")

const int maxn = 2e5+10;
const int mod = 1e9+7;
const ll inf = 1e18+10;
//const int N = 2e6+10;

ll pw(ll a, ll b)
{
    if(b == 0) return 1;
    ll x = pw(a,b/2); x = (x*x) % mod;
    if(b & 1) x = (x*a) % mod;
    return x;
}

int n;
int a[maxn], dp[maxn];
map<int,int> sum;

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>> n;
    for(int i = 1; i <= n; i++)
    {
        cin>> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        if(a[i] == a[i-1]) 
            dp[i] = dp[i-1];
        else
            dp[i] = (dp[i-1] + sum[a[i]]) % mod;
        if(i == 1) dp[i] = 1;
        if(a[i] != a[i+1])
            (sum[a[i]] = dp[i]) %= mod;
     //   cout<< dp[i] <<" "<< sum[a[i]] <<"\n";
    }
    cout<< dp[n];
}
