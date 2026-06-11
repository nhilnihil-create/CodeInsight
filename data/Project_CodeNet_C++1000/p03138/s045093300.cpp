#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,double> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse

ll dp[55][2];

int main() {
    ll n,k;cin>>n>>k;
    ll a[100010];
    rep(i,n) cin>>a[i];

    if(k==0) {
        ll ans = 0;
        rep(i,n) ans += a[i];
        cout<<ans<<endl;
        return 0;
    }

    rep(i,50) {
        rep(j,2) dp[i][j]=-1;
    }

    dp[0][0]=0;

    rep(i,50) {
        int ith_bit = (k >> (50 - i - 1)) & 1;

        ll num_0=0;
        rep(j,n) {
            num_0 += ((a[j] >> (50 - i - 1)) & 1) ^ 0;
            // num_1 += ((a[j] >> (50 - i - 1)) & 1) ^ 1;
        }

        if(dp[i][1] != -1) {
            dp[i+1][1] = max(dp[i+1][1],dp[i][1] + max(num_0,n-num_0) * (1LL<<50-i-1));
        }

        if(dp[i][0] != -1 && ith_bit ==1) {
            dp[i+1][1] = max(dp[i+1][1],dp[i][0] + num_0 * (1LL<<(50-i-1)));
        }

        if(dp[i][0] != -1) {
            if(ith_bit) {
                dp[i+1][0] = max(dp[i+1][0],dp[i][0] + (n - num_0) * (1LL<<(50-i-1))); 
            } else {
                dp[i+1][0] = max(dp[i+1][0],dp[i][0] + num_0 * (1LL<<(50-i-1)));
            }
        }

    }

    cout << max(dp[50][0],dp[50][1]) << endl;
}