#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    llint n;
    cin >> n;

    vector<llint> a(n);
    vector<llint> b(n);
    vector<llint> c(n);
    for(int in=0;in<n;in++) {
        cin >> a.at(in);
    }
    for(int in=0;in<n;in++) {
        cin >> b.at(in);
    }
    for(int in=0;in<n;in++) {
        cin >> c.at(in);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    llint ans=0;
    for(int ib=0;ib<n;ib++) {
        auto ia = lower_bound(a.begin(), a.end(), b.at(ib));
        auto ic = lower_bound(c.begin(), c.end(), b.at(ib)+1);
        ans += (ia-a.begin())*(n-(ic-c.begin()));
    }
    cout << ans << endl;
    return 0;
}

