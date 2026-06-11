#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int N, K; cin >> N >> K;
    ll a[N]; rep(i, N) cin >> a[i];
    ll sum[N + 1]; //sum[i] : [0, i) の和
    sum[0] = 0;
    rep(i, N) sum[i + 1] = sum[i] + a[i];
    vector<ll> b;
    for(int i = 0; i < N; ++i) {
        for(int j = i + 1; j <= N; ++j) {
            b.pb(sum[j] - sum[i]);
        }
    }
    ll ans = 0;
    for(ll i = 40; i >= 0; --i) {
        int cnt = 0;
        for(ll v : b) {
            if(((ans + ll(1LL << i)) & v) == (ans + ll(1LL << i))) ++cnt;
        }
        if(cnt >= K) ans += ll(1LL << i);
    }
    cout << ans << endl;
}
