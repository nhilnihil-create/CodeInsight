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
// #define pre 0.00000000000000000001
#define inf 100000000
#define mod 1000000007
#define endl '\n'
string s;
ll n;
ll dp[3005][3005];
ll pre[3005][3005];
int main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
    cin >> s;
    memset(pre,0,sizeof(pre));
    pre[1][1] = 1;
    fr(i,2,n+1) {
        fr(j,1,i+1) {
            ll l,r;
            if(s[i - 2] == '<') {
                l = 1;r = j - 1;
            }
            else {
                l = j;
                r = i - 1;
            }
            dp[i][j]=(dp[i][j] + pre[i - 1][r] - pre[i - 1][l -1]) % mod;
            //     fr(k,1,i) {
            //         ll num = k;
            //         if(k == j)
            //             num++;
            //         if((num < j) != (s[i - 2] == '<'))
            //             continue;
            //         dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
            // }
        pre[i][j] = pre[i][j - 1] + dp[i][j];
        }
    }
    ll ans = 0;
    fr(i,1,n+1)
        ans = (ans + dp[n][i]) % mod;
    cout << ans;
    return 0;
}	