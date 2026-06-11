#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define vi vector<int>
#define vl vector<long long>
#define vvi vector< vector<int> >
#define vvl vector< vector<ll> >
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPD(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define FORD(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define INF 1e18
#define INFTY 1e9
#define MOD 1e9+7
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

template<class T> bool chmax(T &a, const T & b) {
    if (a<b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> bool chmin(T &a, const T & b) {
    if (a>b) {
        a = b;
        return true;
    }
    return false;
}

struct edge {int to, cost;};
vector< vector<edge> > es;
const int MAX_N = 100010;
const int MAX_M = 10010;
int n, m;
vi a, b, c;

int main() {
    cin >> n;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];
    REP(i, n) cin >> c[i];

    sort(a.begin(), a.end());
    sort(c.begin(), c.end());
    ll ans = 0;
    REP(i, n) {
        auto p = lower_bound(a.begin(), a.end(), b[i]);
        ll cnt1 = p - a.begin();
        auto q = upper_bound(c.begin(), c.end(), b[i]);
        ll cnt2 = c.end() - q;
        //cout << p << ' ' << n-q << endl;
        ans += cnt1*cnt2;
    }
    cout << ans << endl;
    return 0;
}