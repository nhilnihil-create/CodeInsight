//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

struct edge {
    int from, to;
    int64_t cost;
    edge(int x=0, int y=0, int64_t z=0):to(y), from(x), cost(z) {}
};


int main() {
    int n;
    n = 14;
    int l;
    cin >> l;
    cout << n << endl;
    int x = 1;

    vector<edge> ans;
    
    rep(i, 12) {
        rep(j, 3) {
            ans.push_back(edge(i+1, i+2, x*j));
        }
        x *= 3;
    }
    for(int i=13; i>0; --i) {
        while(l >= x) {
            l -= x;
            ans.push_back(edge(i, 14, l));
        }
        x /= 3;
    } 

    cout << ans.size() << endl;
    for(edge e:ans) {
        cout << e.from << ' ' << e.to << ' ' << e.cost << endl;
    }

}