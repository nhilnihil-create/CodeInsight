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


int main(){
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x);
    vector<ll> b(y);
    vector<ll> c(z);
    rep(i, x) cin >> a[i];
    rep(i, y) cin >> b[i];
    rep(i, z) cin >> c[i];
    sort(whole(a)); reverse(whole(a));
    sort(whole(b)); reverse(whole(b));
    sort(whole(c)); reverse(whole(c));
    vector<ll> ab;
    rep(i, x) rep(j, y) {
        ab.push_back(a[i]+b[j]);
    }
    sort(whole(ab));
    reverse(whole(ab));
    ll nab = ab.size();

    priority_queue<ll> q;
    rep(i, z) {
        ll temp = min(k, nab);
        rep(j, temp) {
            q.push(c[i] + ab[j]);
        }
    }

    rep(i, k) {
        cout << q.top() << endl;
        q.pop();
    }
    return 0;
}
