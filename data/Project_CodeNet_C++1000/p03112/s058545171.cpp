#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;
typedef tuple<long long, long long, long long> tllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
bool compTuple(const tllint& arg1, const tllint& arg2) { return get<2>(arg1) > get<2>(arg2); }
template<class T> bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void) {
    llint a, b, q;
    cin >> a >> b >> q;

    vector<llint> s(a+2);
    vector<llint> t(b+2);
    s[0] = -1e18;
    s[a+1] = 1e18;
    t[0] = -1e18;
    t[b+1] = 1e18;

    for(llint ia=0;ia<a;++ia) cin >> s[ia+1];
    for(llint ib=0;ib<b;++ib) cin >> t[ib+1];

    llint x, ans;
    for(llint iq=0;iq<q;++iq) {
        ans = 1e18;
        cin >> x;

        auto sb = upper_bound(s.begin(), s.end(), x);
        auto sa = sb - 1;
        auto tb = upper_bound(t.begin(), t.end(), x);
        auto ta = tb - 1;
        chmin(ans, abs(x-*ta)+abs(*ta-*sa));
        chmin(ans, abs(x-*sa)+abs(*ta-*sa));
        chmin(ans, abs(x-*tb)+abs(*tb-*sa));
        chmin(ans, abs(x-*sa)+abs(*tb-*sa));
        chmin(ans, abs(x-*ta)+abs(*ta-*sb));
        chmin(ans, abs(x-*sb)+abs(*ta-*sb));
        chmin(ans, abs(x-*tb)+abs(*tb-*sb));
        chmin(ans, abs(x-*sb)+abs(*tb-*sb));
        cout << ans << endl;
    }

    return 0;
}
