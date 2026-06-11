#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define w(x) int x; cin>>x; while(x--)
#define f(i,n) for(ll i=0;i<n;i++)
#define ff first
#define ss second
const ll INF = 1e18 + 5;

void ganekasar()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll accumulate(vector<ll> v, ll s, ll e)
{
    ll sum = 0;

    for(ll i=s; i<=e; i++)
        sum += v[i];

    return sum;
}

int main() 
{
    ganekasar();
    
    ll n;
    cin>>n;

    vector<ll> a(n);

    ll dp[n][n];

    f(i,n) cin>>a[i];

    for(ll L = n-1; L >= 0; L--)
    {
        for(ll R = L; R < n; R++)
        {
            if(L == R)
                dp[L][R] = 0;
            else
            {
                dp[L][R] = INF;

                ll sum = accumulate(a, L, R);

                for(ll i = L; i < R; i++)
                    dp[L][R] = min(dp[L][R], dp[L][i] + dp[i+1][R] + sum);
            }
        }
    }
    
    cout<< dp[0][n-1] <<endl;

    return 0; 
} 