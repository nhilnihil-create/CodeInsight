    #include<bits/stdc++.h>
    // #include <ext/pb_ds/assoc_container.hpp>
    using namespace std;
    // using namespace _gnu_pbds;
    #define vb __int128
    #define ll long long
    #define ld long double
    #define full(a) a.begin(),a.end()
    #define fr(i,a,b) for(ll i = a ; i < b ; i++)
    #define stoink stack<ll>
    #define quu queue<ll>
    #define quee queue<pair<ll,ll>>
    #define vec vector <ll>
    #define vecd vector<ld>
    #define vg vector<vector<ll> >
    #define eg vector<pair<ll,ll>>
    #define vgw vector<vector<pair<ll,ll> > >
    #define pa pair<ll,ll>
    #define pb push_back
    #define ff first
    #define ss second
    #define pre 0.00000000000000000001
    #define inf 100000000
    #define mod 998244353
    #define endl '\n'
    ll n;
    ll arr[20][20];
    ll val[1 << 20];
    ll dp[1 << 20];
    ll timer = 0;
    ll func(ll mask) {
        if(mask == (1 << n) - 1) {
            return 0;
        }
        if(dp[mask] != -1)
            return dp[mask];
        ll ans = 0;
        ll cnt = 0;
        vec available;
        fr(i,0,n) {
            if(!(mask & (1 << i))) {
                cnt++;
                available.pb(i);
            } 
        }
        for(ll bitmask = 1;bitmask < (1 << cnt) ; bitmask++) {
            ll temp = 0;
            fr(i,0,cnt) {
                if(bitmask & 1 << i) {
                    temp |= (1 << available[i]);
                }
            }
            ans = max(ans,func(mask | temp) + val[temp]);
        }
        return dp[mask] = ans;
    }
    int main()
    {	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
    	cout.tie(NULL);
        memset(dp, -1, sizeof(dp));
        cin >> n;
        fr(i,0,n) fr(j,0,n) cin >> arr[i][j];
        val[0] = 0;
        for(ll mask = 1; mask < (1 << n) ; mask++) {
            vec setbits;
            fr(i,0,n) {
                if((1 << i) & mask) {
                    setbits.pb(i);
                }
            }
            ll res = 0;
            for(int i = 0 ; i < setbits.size() - 1; i++) {
                for(int j = i + 1 ; j < setbits.size() ; j++) {
                    res += arr[setbits[i]][setbits[j]]; 
                }
            }
            val[mask] = res;
        }
        ll ans = 0;
        for(int mask = 1 ; mask < 1 << n ; mask++) {
            ans = max(ans,val[mask] + func(mask));
        }
        cout << ans;
        return 0;
    }	