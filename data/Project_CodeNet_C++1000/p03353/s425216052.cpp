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
        string s; cin >> s;
        int k; cin >> k;
        int n = sz(s);
        vector<string> a;
        for (int i = 0; i < n; i++) {
                string ss;
                for (int j = i; j < n && j - i + 1 <= k; j++) {
                        ss += s[j];
                        a.emplace_back(ss);
                }
        }

        sort(all(a));
        a.resize(unique(all(a)) - a.begin());
        cout << a[k - 1] << '\n';
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
