#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define INIT    \
    cin.tie(0); \
    ios::sync_with_stdio(false);

template <class T>
inline bool chmax(T& a, T b) {
    return a = (a < b) ? b : a;
}
template <class T>
inline bool chmin(T& a, T b) {
    return a = (a > b) ? b : a;
}

ll const INF = 1LL << 60;
ll const MOD = 1000000007;

std::vector<int> find_all(const std::string str, const std::string subStr) {
    std::vector<int> result;

    int subStrSize = subStr.size();
    int pos = str.find(subStr);

    while (pos != std::string::npos) {
        result.push_back(pos);
        pos = str.find(subStr, pos + subStrSize);
    }

    return result;
}

int main() {
    INIT;

    string s;
    cin >> s;

    bool flg = false;
    rep(i, 10) {
        string sc = to_string(i) + to_string(i) + to_string(i);
        vector<int> f = find_all(s, sc);
        if (SZ(f) > 0) {
            flg = true;
        }
    }

    if (flg) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}