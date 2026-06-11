#include<bits/stdc++.h> 
using namespace std;

#define ll long long int
#define absdiff(a,b) (a>b)?a-b:b-a
#define mp make_pair 
#define pb push_back
#define pp pop_back
#define ff first
#define ss second
#define fast  ios_base::sync_with_stdio(false);cin.tie(0);
#define endl "\n"
const ll ll_MAX = 1922337203685;
const ll MOD = 998244353;
ll fast_expo(ll x,ll p){if(p==0) return 1;
    else if(p%2==0){ ll t=fast_expo(x,p/2)%MOD;return (t*t)%MOD;} 
    else return (x*(fast_expo(x,p-1))%MOD)%MOD;}
ll gcd(ll a,ll b){if(a==0||b==0) return a+b;  
    else return gcd(b%a,a); }
    
int main()
{
    fast
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    ll t_c; t_c = 1;
    // cin >> t_c;
    for(ll t_i=0; t_i<t_c; ++t_i){
        ll n; cin >> n;
        ll mat[n][n];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j)
                cin >> mat[i][j];
        }

        ll dp[1<<n];
        fill_n(dp, 1<<n, -ll_MAX);

        dp[0] = 0;
     	vector<int> arr;
        for(int i = 1; i < (1<<n); ++i){
            int temp = i;
            arr.clear();
            for(int j = 0; j < n; ++j){
                if(temp&(1<<j))
                    arr.pb(j);
            }

            int x = arr.size();

            for(int j = 1; j < (1<<x)-1; ++j){
                int val1 = 0;
                for(int k = 0; k < x; ++k){
                    if(j&(1<<k)){
                        val1 += (1<<arr[k]);
                    }
                }

                int val2 = (i^val1);
                dp[i] = max(dp[i], dp[val1]+dp[val2]);
            }

            ll sum = 0;
            for(int j = 0; j < arr.size(); ++j){
                for(int k = j+1; k < arr.size(); ++k)
                    sum += mat[arr[j]][arr[k]];
            }

            dp[i] = max(dp[i], sum);
        }
        cout << dp[(1<<n)-1];
    }  
    return 0;
}