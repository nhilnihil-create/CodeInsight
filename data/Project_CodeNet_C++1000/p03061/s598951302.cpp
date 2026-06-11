#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(pos,mp) for(ll pos=mp.begin();pos!=mp.end();pos -++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

ll gcd(ll a,ll b){
    if(a < b)swap(a, b);

	if(a%b == 0)return(b);

	else return(gcd(b, a%b));
}

int main(){
    ll n;
    cin >> n;

    ll a[n];
    rep(i, n)cin >> a[i];

    // 左向きと右向きの累積gcd
    ll left_gcd[n], right_gcd[n];
    left_gcd[0] = a[0];
    right_gcd[n-1] = a[n-1];

    rep(i, n-1){
        left_gcd[i+1] = gcd(left_gcd[i], a[i+1]);
        right_gcd[n-i-2] = gcd(right_gcd[n-1-i], a[n-i-2]);
    }

    ll ans = 1;
    // a[i]を抜いたgcdを求めていく
    rep(i, n){
        if(i == 0)ans = max(ans, right_gcd[i+1]);
        else if(i == n-1)ans = max(ans, left_gcd[i-1]);
        else {
            ll res = gcd(left_gcd[i-1], right_gcd[i+1]);
            ans = max(ans, res);
        }
    }

    cout << ans << endl;
}