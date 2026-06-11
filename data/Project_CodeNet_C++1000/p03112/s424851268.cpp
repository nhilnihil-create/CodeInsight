#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
const ll INF = 1E+15;


int main(){
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a);
    vector<ll> t(b);
    rep(i, a) cin >> s[i];
    rep(i, b) cin >> t[i];
    rep(i, q) {
        ll x;
        cin >> x;
        ll s1, s2, t1, t2;
        auto its = lower_bound(whole(s), x);
        if (its==s.end()) s2 = INF;
        else s2 = *its;
        if (its==s.begin()) s1 = -INF;
        else {
            its--;
            s1 = *its;
        }
        auto itt = lower_bound(whole(t), x);
        if (itt==t.end()) t2 = INF;
        else t2 = *itt;
        if (itt==t.begin()) t1 = -INF;
        else {
            itt--;
            t1 = *itt;
        }
        ll res = INF;
        chmin(res, max(s2, t2)-x);
        chmin(res, x-min(s1, t1));
        chmin(res, (x-s1)*2+(t2-x));
        chmin(res, (x-t1)*2+(s2-x));
        chmin(res, (s2-x)*2+(x-t1));
        chmin(res, (t2-x)*2+(x-s1));
        cout << res << endl;
    }
    
    return 0;
}
