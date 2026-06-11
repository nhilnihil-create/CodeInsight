#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<ll> 
#define all(x) (x).begin() , (x).end()
#define inf 1000000000
#define mod 1000000007

void dbg(){
	cerr << endl;
}
template<typename Head , typename... Tail>
void dbg(Head h , Tail... t){
	cerr << h << " ";
	dbg(t...);
}

#ifdef EMBI_DEBUG
#define debug(...) cerr << "(" << #__VA_ARGS__  << "): ", dbg(__VA_ARGS__)
#else 
#define debug(...)
#endif

const int max_n = 1e5 + 9;

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
void solve(){
	int h , w;
    cin >> h >> w;

    string s[h];
    for(int i = 0 ; i < h ; i++){
        cin >> s[i];
    }

    int dp[h][w];
    memset(dp , 0 , sizeof(dp));
    dp[0][0] = 1;
    for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
            if(s[i][j] == '#'){
                dp[i][j] = 0;
            }
            else{
                if(i - 1 >= 0)dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
                if(j - 1 >= 0)dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
            }
            // cout << dp[i][j] << " ";
        }
        // cout << "\n";
    }
    cout << dp[h-1][w-1] << "\n";
}
signed main(){
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
	}
}