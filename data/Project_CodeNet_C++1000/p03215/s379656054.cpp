#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

typedef long long ll;
typedef pair<ll, ll> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976
const double PI = 3.1415926535897932;

ll cnt[1010];
int main()
{
    int n,k; cin >> n >> k;
    vector<ll> v;
    rep(i,n) cin >> cnt[i+1];
    rep(i,n) cnt[i+1] += cnt[i];
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n+1; j++){
            v.push_back(cnt[j]-cnt[i]);
        }
    }
    ll ans = 0;
    for(int i = 40; i >= 0; i--){
        ll cur = ans + (1LL << i);
        int ok = 0;
        for(auto tmp : v) if((cur & tmp) == cur) ok++;
        if(ok >= k) ans = cur;
    }
    cout << ans << endl;
}