#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for(ll i = 0; i < (n); i++)
#define REP2(i, x, n) for(ll i = x; i < (n); i++)
const long long INF = numeric_limits<long long>::max();
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

ll maps[3][3];
vector<vector<ll>> calcFunc() {

    for(ll a1 = 0; a1 <= 100; ++a1) {
        ll b1 = maps[0][0] - a1;
        if(b1 < 0) continue;

        ll a2 = maps[1][0] - b1;
        if(a2 < 0) continue;
        ll b2 = maps[1][1] - a2;
        if(b2 < 0) continue;

        ll a3 = maps[2][0] - b1;
        if(a3 < 0) continue;
        ll b3 = maps[0][2] - a1;
        if(b3 < 0) continue;

        if(a1 + b2 != maps[0][1]) continue;

        if(a2 + b3 != maps[1][2]) continue;

        if(a3 + b2 != maps[2][1]) continue;
        if(a3 + b3 != maps[2][2]) continue;

        vector<vector<ll>> vec(2);
        vec[0].push_back(a1);
        vec[0].push_back(a2);
        vec[0].push_back(a3);

        vec[1].push_back(b1);
        vec[1].push_back(b2);
        vec[1].push_back(b3);
        return vec;
    }
    return {};
}
bool func() {

    auto vec = calcFunc();
#ifdef SOURCE_TEST

    for(ll i = 0; i < vec.size(); ++i) {
        for(ll j = 0; j < vec[i].size(); ++j) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
#endif
    return vec.size() != 0;
}
int main() {

    for(ll i = 0; i < 3; ++i) {
        for(ll j = 0; j < 3; ++j) {
            cin >> maps[i][j];
        }
    }

    cout << (func() ? "Yes" : "No") << endl;

    return 0;
}