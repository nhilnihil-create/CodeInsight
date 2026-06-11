#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(long long)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

template<class T> void vin(vector<T>& v, int n) {
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

struct Edge {
    int s, t, w;
};

int main() {
    int L;
    cin >> L;
    int r = log2(L);
    r = min(r, 19);
    int n = r + 1;
    vector<Edge> g;

    rep(i, r) {
        Edge e1, e2;
        e1.w = 0;
        e1.s = i+1;
        e1.t = i+2;
        e2.w = pow(2, i);
        e2.s = i+1;
        e2.t = i+2;
        g.push_back(e1);
        g.push_back(e2);
    }
    bool update = true;
    for (int t=n-1; t>=1; --t) {
        if (L - pow(2, t-1) >= pow(2, r)) {
            Edge e;
            e.w = L - pow(2, t-1);
            e.s = t;
            e.t = n;
            g.push_back(e);
            L -= pow(2, t-1);
        }
    }
    cout << n << ' ' << g.size() << endl;
    for (auto v : g) {
        cout << v.s << ' ' << v.t << ' ' << v.w << endl;
    }
}
