#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;
void  add(ll h[] , ll pos , ll val)
{
    h[pos] += val;
    if(h[pos] >= mod)
    h[pos] -= mod;
}


void  sub(ll h[] , ll pos , ll val)
{
    h[pos] -= val;
    if(h[pos] < 0)
    h[pos] += mod;
} 


int main() {
    ll n , k;
    cin >> n >> k;
    ll a[n+1];
    for(ll i = 1 ; i  <= n ; i++)
    cin >> a[i];
    ll dp[k+1];
    memset(dp , 0 , sizeof(dp));
    dp[0] = 1;  
    for(ll i = 1 ; i <= n ; i++)
    {
        ll h[k+1]= {0};
        for(ll j = k ; j >= 0 ; j--)
        {
            ll adder = dp[j];
            ll left = j + 1;
            ll right = j + min(a[i] , (k-j));
            if(left <= right)
            {
                add(h , left , adder);
                if(right+1 <= k)
                sub(h , right+1 , adder);
            }
        }


        ll pre = 0;
        for(ll j = 0 ; j  <= k ; j++)
        {
            pre = pre + h[j];
            if(pre >= mod)
            pre -= mod;
            dp[j] = dp[j] + pre;
            if(dp[j] >= mod)
            dp[j] -= mod;
        }
    }


    cout << dp[k] ;
}
