#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

const int MAX_DEGIT = 50;
int main(){
    ll n, k;
    cin >> n >> k;

    ll cnt[MAX_DEGIT] = {};
    rep(i, n){
        ll a;
        cin >> a;
        rep(j, MAX_DEGIT)if((1LL<<j) & a)cnt[j]++;
    }

    //dp[i][1] = 上位i桁目までを決めて，かつkより小さい
    ll dp[MAX_DEGIT+1][2] = {};
    rep(i, MAX_DEGIT+1)dp[i][1] = -1;
    
    rep(i, MAX_DEGIT){
        ll base = (1LL<<(MAX_DEGIT-i-1));

        ll cost_up = base * (n - cnt[MAX_DEGIT-i-1]);
        ll cost_down = base * cnt[MAX_DEGIT-i-1];

        //既にkより小さく行けているのなら自由にビットを立てる
        if(dp[i][1] >= 0){
            dp[i+1][1] = dp[i][1] + max(cost_up, cost_down);
        }

        if(base & k){
            //ギリギリの物からビットを下げてkより小さくする
            dp[i+1][1] = max(dp[i+1][1], dp[i][0] + cost_down);
            dp[i+1][0] = dp[i][0] + cost_up;
        }
        else {
            dp[i+1][0] = dp[i][0] + cost_down;
        }
    }

    cout << max(dp[MAX_DEGIT][0], dp[MAX_DEGIT][1]) << endl;
}