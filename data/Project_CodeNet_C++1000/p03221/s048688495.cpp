#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9+7;

int main() {
    int N, M;
    cin >> N >> M;
    vector<tuple<int, int, int>> v(M);
    REP(i, M) {
        int p, y;
        cin >> p >> y;
        v[i] = make_tuple(i, p, y);
    }
    sort(ALL(v), [](auto x, auto y){return get<1>(x) != get<1>(y) ? get<1>(x) < get<1>(y) : get<2>(x) < get<2>(y);});
    map<int, int> dic;
    REP(i, M) {
        int f, s, t;
        tie(f, s, t) = v[i];
        dic[s] += 1;
        v[i] = make_tuple(f, s, dic[s]);
    }
    sort(ALL(v));
    REP(i, M) {
        int s, t;
        tie(ignore, s, t) = v[i];
        printf("%06d", s);
        printf("%06d\n", t);
    }
    return 0;
}

