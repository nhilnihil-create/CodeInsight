//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<ll>;
using vvi = vector<vi>;



int main() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vi a(x), b(y), c(z);
    rep(i, x) {
        cin >> a[i];
    }
    rep(i, y) {
        cin >> b[i];
    }
    rep(i, z) {
        cin >> c[i];
    }

    sort(rall(a));
    sort(rall(b));
    sort(rall(c));
    priority_queue<tuple<ll, int, int, int> > Q;
    Q.push(make_tuple(a[0]+b[0]+c[0], 0, 0, 0)); 
    vector<vector<vector<bool> > > check(x, vector<vector<bool> >(y, vector<bool>(z, false)));
    check[0][0][0] = true;

    rep(i, k) {
        auto qq = Q.top();
        Q.pop();
        ll m_;
        int a_, b_, c_;
        tie(m_, a_, b_, c_) = qq;

        cout << m_ << endl;
        if(a_ != x-1 && !check[a_+1][b_][c_]) {
            check[a_+1][b_][c_] = true;
            Q.push(make_tuple(a[a_+1]+b[b_]+c[c_], a_+1, b_, c_));
        }
        if(b_ != y-1 && !check[a_][b_+1][c_]) {
            check[a_][b_+1][c_] = true;
            Q.push(make_tuple(a[a_]+b[b_+1]+c[c_], a_, b_+1, c_));
        }
        if(c_ != z-1 && !check[a_][b_][c_+1]) {
            check[a_][b_][c_+1] = true;
            Q.push(make_tuple(a[a_]+b[b_]+c[c_+1], a_, b_, c_+1));
        }
    }
}