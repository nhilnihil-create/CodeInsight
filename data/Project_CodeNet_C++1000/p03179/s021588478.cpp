#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << '\n'
#define debug_arr(a , n) for(int i = 0 ; i < n ; i++)cout << a[i] << " "
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll> 
#define inf 1000000000
#define mod 1000000007

const int max_n = 3e3 + 9;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
ll power(ll a , ll b)
{
    ll prod = 1;
    while(b)
    {
        if(b&1)
        prod = (prod*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return prod;
}
int dp[max_n][max_n];

void add(int &a , int b){
    a = (a + b)%mod;
}
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    dp[1][1] = 1;
    for(int i = 2 ; i <= n ; i++){
        int pref[i+1] = {0};
        for(int j = 1 ; j <= i-1 ; j++){
            pref[j] = (pref[j-1] + dp[i-1][j])%mod;
        }
        for(int last = 1 ; last <= i ; last++){
            // for(int j = 1 ; j <= i-1 ; j++){
            //     int num = j;
            //     if(j >= last){
            //         num++;
            //     }
            //     assert(num != last);
            //     if(s[i-2] == '<' && num < last){
            //         add(dp[i][last] , dp[i-1][j]);
            //     }
            //     if(s[i-2] == '>' && num > last){
            //         add(dp[i][last] , dp[i-1][j]);
            //     }
            // }

            int l , r;
            if(s[i-2] == '<'){
                l = 1 , r = last - 1;
            }
            else {
                l = last , r = i-1;
            }
            add(dp[i][last] , (pref[r] - pref[l-1] + mod)%mod);
        }
    }

    int ans = 0;
    for(int i = 1 ; i <= n ; i++){
        add(ans , dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}