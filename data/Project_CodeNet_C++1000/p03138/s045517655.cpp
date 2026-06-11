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
    llint n, k;
    cin >> n >> k;

    vector<llint> a(n);
    vector<llint> atmp(n);
    for(llint in=0;in<n;++in) {
        cin >> a[in];
        atmp[in] = a[in];
    }

    llint cnt = 0, pow2 = 1;
    while(pow2<k) { 
        cnt++;
        pow2 *= 2;
    }

    llint x = 0, cnt0, cnt1;
    for(llint ic=cnt;ic>=0;--ic) {
        cnt1 = 0;
        cnt0 = 0;
        for(llint in=0;in<n;++in) {
            if((atmp[in]/pow2)&1) cnt1++;
            atmp[in] %= pow2;
        }
        cnt0 = n - cnt1;
        if(cnt0>cnt1&&x+pow2<=k) x += pow2;
        // cout << cnt0 << cnt1 << x << endl;
        pow2 /= 2;
    }

    llint ans = 0;
    for(auto ia:a) ans += ia ^ x;
    cout << ans << endl;
    return 0;
}
