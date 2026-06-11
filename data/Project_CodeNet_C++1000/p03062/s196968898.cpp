//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n;
    cin >> n;
    ll ans = 0;
    ll mi = LINF;
    int odd = 0;
    rep(i, n) {
        ll a;
        cin >> a;
        if(a<0) {
            odd = ~odd;
        }
        a = abs(a);
        ans += a;
        mi = min(mi, a);
    }

    if(odd) {
        ans -= 2*mi;
    }

    cout << ans << endl;
}