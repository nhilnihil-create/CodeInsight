#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using st = string;
#define mrep(i, m, n) for(int i = m; i < n; i++)
#define rep(i, n) mrep(i, 0, n)
#define chmax(x, y) { x = max(x, y); }
#define chmin(x, y) { x = min(x, y); }
#define mp(x, y) make_pair(x, y)
#define mt(x, y, z) make_tuple(x, y, z)

int main() {
    int n;
    cin >> n;
    vector<tuple<string, int, int>> sp(n);
    rep(i, n){
        string s;
        int p;
        cin >> s >> p;
        int x = i + 1;
        sp.at(i) = mt(s, p, x);
    }
    sort(sp.begin(), sp.end());
    rep(i, n - 1){
        mrep(j, i + 1, n){
            string s1 = get<0>(sp.at(i));
            string s2 = get<0>(sp.at(j));
            if(s1 == s2){
                int i1 = get<1>(sp.at(i));
                int i2 = get<1>(sp.at(j));
                if(i1 < i2){
                    tuple<string, int, int> t = sp.at(i);
                    sp.at(i) = sp.at(j);
                    sp.at(j) = t;
                }
            }
        }
    }
    rep(i, n){
        string s;
        int p;
        int x;
        tie(s, p, x) = sp.at(i);
        cout << x << endl;
    }
    return 0;
}