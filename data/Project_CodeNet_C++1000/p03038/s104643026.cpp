#include <bits/stdc++.h>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr int INF = 1001001001;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

bool comp(P a, P b) {return a.second > b.second;}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep (i, n) cin >> a[i];
    vector<P> p(m);
    rep (i, m) {
        int b, c;
        cin >> b >> c;
        p[i] = make_pair(b, c);
    }
    
    sort(p.begin(), p.end(), comp);
    priority_queue<int> q;
    for (auto v : a) q.push(v);
    rep (i, m) {
        int b = p[i].first, c = p[i].second;
        rep (j, b) q.push(c);
        if (q.size() > n*2)
            break;
    }
    
    ll ans = 0;
    rep(i,n) {
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
    
    return 0;
}
