#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const int INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int N; cin >> N;
    ll A[N]; rep(i, N) cin >> A[i];
    ll sum[N + 1]; //[0, i) の和
    map<ll, ll>mp;
    sum[0] = 0;
    mp[0]++;
    rep(i, N) sum[i + 1] = sum[i] + A[i], mp[sum[i + 1]]++;
    ll ans = 0;
    for(auto i = mp.begin(); i != mp.end(); ++i) {
        ans += (i->second) * (i->second - 1) / 2;
    }
    cout << ans << endl;
}
