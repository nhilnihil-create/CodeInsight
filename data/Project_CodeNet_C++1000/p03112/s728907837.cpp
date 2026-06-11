#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1e11+1;
const vector<int> di = {-1,  0, 1, 0};
const vector<int> dj = { 0, -1, 0, 1};

void chmin(int &a, int b) { if (a > b) a = b; }

ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
ll LCM(ll a, ll b) { return a * b / GCD(a, b); }


template<class T>
int former(const vector<T> &v, T x) {
    return upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
}

template<class T>
int latter(const vector<T> &v, T x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}



int main(){
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a, 0), t(b, 0), x(q, 0);

    rep(i, a) cin >> s[i];
    rep(i, b) cin >> t[i];
    rep(i, q) cin >> x[i];

    s.push_back(INF);
    s.push_back(-INF);
    t.push_back(INF);
    t.push_back(-INF);
    sort(all(s));
    sort(all(t));

    for(auto xx: x) {
        ll res = INF;
        // 最初にsに行く
        rep(i, 2) {
            ll first = (i ? s[former(s, xx)] : s[latter(s, xx)]);
            rep(j, 2) {
                ll second = (j ? t[former(t, first)] : t[latter(t, first)]);
                res = min(res, abs(xx - first) + abs(first - second));
            }
        }
        rep(i, 2) {
            ll first = (i ? t[former(t, xx)] : t[latter(t, xx)]);
            rep(j, 2) {
                ll second = (j ? s[former(s, first)] : s[latter(s, first)]);
                res = min(res, abs(xx - first) + abs(first - second));
            }
        }
        cout << res << endl;
    }

}