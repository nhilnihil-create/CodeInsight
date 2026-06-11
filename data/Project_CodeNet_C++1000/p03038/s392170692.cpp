#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}



void _main() {
        int n, m; cin >> n >> m;
        priority_queue<int> u, v;
        for (int i = 0; i < n; i++) {
               int x; cin >> x;
               u.emplace(x);
        }

        vector<pair<int,int>> b(m);
        for (int i = 0; i < m; i++) cin >> b[i].second >> b[i].first;
        sort(all(b), greater<>());
        for (int i = 0; i < m; i++) {
                for (int j = 0; j < b[i].second; j++) {
                        if (v.size() < n) v.emplace(b[i].first);
                        else break;
                }
        }


        while (v.size()) {
                u.emplace(v.top());
                v.pop();
        }

        ll ans = 0;
        while (n--) {
                ans += u.top();
                u.pop();
        }

        cout << ans;
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
