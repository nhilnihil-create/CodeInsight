#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<tuple>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(ll i = 1;i <=  n; i++)
#define rrep(i,n) for(ll i = n -1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
#define RALL(a) rbegin(a),rend(a)
typedef long long int ll;
typedef long double ld;
const ll INF = 1e18;
const double eps = 1e-8;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}ll n, m, s, t, r, Q, b, c,x; 
vector<ll> a,f,D;
const int MOD = 1e9 + 7;
bool ch(ll x) {
    ll sum = 0;
    rep(i, n) {
        sum += max(a[i] - x / f[i],0LL);
    }return sum <= m;
}
int main(void) {
    cin >> n >> m >> Q; a.resize(n); f.resize(m); 
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> f[i];
    rep(i, Q) {
        cin >> x;
        ll ans = INF;
        int idx1 = lower_bound(ALL(a), x) - a.begin();
        int idx2 = lower_bound(ALL(f), x) - f.begin();
        if (idx1 < n && idx2 < m) ans = min(ans, abs(x - max(a[idx1], f[idx2])));
        if (idx1 > 0 && idx2 < m) ans = min(ans, abs(x - a[idx1 - 1]) + abs(a[idx1 - 1] - f[idx2]));
        if (idx1 > 0 && idx2 < m) ans = min(ans, abs(x - f[idx2]) + abs(f[idx2] - a[idx1 - 1]));
        if (idx1 < n && idx2 > 0) ans = min(ans, abs(x - f[idx2 - 1]) + abs(f[idx2 - 1] - a[idx1]));
        if (idx1 < n && idx2 > 0) ans = min(ans, abs(x - a[idx1]) + abs(a[idx1] - f[idx2 - 1]));
        if (idx1 > 0 && idx2 > 0) ans = min(ans, abs(x - min(a[idx1 - 1], f[idx2 - 1])));
        cout << ans << endl;
    }
}
