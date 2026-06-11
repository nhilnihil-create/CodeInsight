#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

int main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int, int>> t;
    rep (i, m) {
        int p, y;
        cin >> p >> y;
        t.emplace_back(make_tuple(p, y, i, 0));
    }
    sort(all(t));
    int prep = get<0>(t[0]);
    int ctr = 0;
    rep (i, m) {
        if (get<0>(t[i]) == prep) {
            get<3>(t[i]) = ++ctr;
        } else {
            get<3>(t[i]) = 1;
            ctr = 1;
            prep = get<0>(t[i]);
        }
    }
    rep (i, m) {
        swap(get<0>(t[i]), get<2>(t[i]));
    }
    sort(all(t));

    rep (i, m) {
        int p = get<2>(t[i]);
        int y = get<3>(t[i]);
        printf("%06d%06d\n", p, y);
    }
}
