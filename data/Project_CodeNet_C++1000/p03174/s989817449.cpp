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
#define vg vector<vector<ll> >
#define eg vector<pair<ll,ll>>
#define vgw vector<vector<pair<ll,ll> > >
#define pa pair<ll,ll>
#define pb push_back
#define ff first
#define ss second
#define pre 0.00000000000000000001
#define inf 100000000000000000
#define mod (ll)(1e9 + 7)
#define endl '\n'
int main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    ll n;
    cin >> n;
    vec dp(1 << n);
    ll mask = 0;
    ll arr[30][30];
    fr(i,0,n) fr(j,0,n) cin >> arr[i][j];
    dp[0] = 1;
    for(mask = 0 ; mask < ((1 << n) - 1) ; mask++) {
        ll cnt = __builtin_popcount(mask);
        fr(i,0,n) {
            if(arr[cnt][i] == 0 || (1 << i) & mask)
                continue;
            dp[mask | 1 << i] = (dp[mask | 1 << i] + dp[mask]) % mod;
        }
    }
    cout << dp[(1 << n) - 1];
	return 0;
}