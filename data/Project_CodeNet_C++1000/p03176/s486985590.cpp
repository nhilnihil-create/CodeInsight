#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll h[200001] , a[200001];
ll mod = 1e9+7;
ll seg[800001];
ll dp[200001];

void Update(ll s , ll e , ll index , ll pos , ll val)
{
    if(index > e || index < s)
    return ;
    if(s == index && e == index)
    {
        seg[pos] = val;
        return;
    }

    ll mid=(s+e)/2;
    Update(s , mid , index , 2*pos , val);
    Update(mid+1 , e , index , 2*pos+1 , val);
    seg[pos] = max(seg[2*pos] , seg[2*pos+1]);
}


ll query(ll qs , ll qe , ll s , ll e , ll pos){
    if(s > qe || e < qs)
    return 0;
    if(s >= qs && e <= qe)
    return seg[pos];

    ll mid= (s+e)/2;
    return max(query(qs , qe , s , mid , 2*pos) , query(qs , qe , mid+1 , e , 2*pos+1));
}



int main() { 
    ll n;
    cin >> n;
    for(ll i = 1 ; i <= n  ;i++)
    cin >> h[i];
    for(ll i = 1 ; i <= n ; i++)
    cin >> a[i];
    
    memset(dp , 0 , sizeof(dp));
    ll ans = 0;
    for(ll i = 1 ; i<= n ; i++)
    {   
        ll max_val = query(1 , h[i]-1 , 1 , n , 1);
        dp[h[i]] = a[i] + max_val;
        ans= max(ans , dp[h[i]]);
        Update(1 , n , h[i] , 1 , dp[h[i]]);
    }

    cout << ans ;
    
}
