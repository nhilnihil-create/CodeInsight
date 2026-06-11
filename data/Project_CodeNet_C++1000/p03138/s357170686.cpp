#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse

ll a[100010];

ll dp[60][2];

int main () {

    ll n,k;cin>>n>>k;

    rep(i,n) cin>>a[i];

    memset(dp,-1,sizeof(dp));

    dp[0][0]=0;

    rep(i,50) {
        ll mask = 1LL<<(50-i-1);
        ll cnt=0;
        rep(j,n) if(a[j]&mask) cnt++;
        ll del0 = cnt*mask;
        ll del1 = (n-cnt)*mask;
        if (dp[i][0]!=-1) {
            if (k&mask) {
                dp[i+1][0]=max(dp[i+1][0],dp[i][0]+del1);
                dp[i+1][1]=max(dp[i+1][1],dp[i][0]+del0);
            } else {
                dp[i+1][0]=max(dp[i+1][0],dp[i][0]+del0);
            }
        }
        if (dp[i][1]!=-1) {
            dp[i+1][1]=max(dp[i+1][1],dp[i][1]+max(del0,del1));
        }
    }

    cout<<max(dp[50][0],dp[50][1])<<endl;

}