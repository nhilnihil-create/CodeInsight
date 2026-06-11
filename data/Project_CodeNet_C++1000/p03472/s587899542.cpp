#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    ll N, H;
    cin >> N >> H;
    
    vector<ll> a(N), b(N);
    rep(i, N) cin >> a[i] >> b[i];

    sort(all(a));
    reverse(all(a));
    sort(all(b));
    reverse(all(b));

    ll max_a = a[0];
    ll ans = 0;
    rep(i, N) {
        if (b[i] >= max_a) {
            ans++;
            H -= b[i];
        }
        if (H <= 0) {
            H = 0;
            break;
        }
    }
    
    ans += (H + max_a - 1LL) / max_a;

    cout << ans << endl;
    return 0;
}