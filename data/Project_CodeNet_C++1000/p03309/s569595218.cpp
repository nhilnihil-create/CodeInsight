#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i] -= i + 1;
    }

    sort(a.begin(), a.end());
    ll d;
    if (n % 2 == 1) {
        d = a[n / 2];
    }
    else {
        d = (a[n / 2 - 1] + a[n / 2]) / 2;
    }

    ll res  = 0;
    rep(i, n) {
        res += abs(a[i] - d);
    }

    cout << res << endl;
    
    return 0;
}