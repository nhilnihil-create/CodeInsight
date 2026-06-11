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
    ll n, a, b, c, d, e;
    cin >> n >> a  >> b >> c >> d >> e;
    ll mi = min({a, b, c, d, e});
    ll ans = (mi+n-1)/mi;

    ans += 4;
    cout << ans << endl;
}