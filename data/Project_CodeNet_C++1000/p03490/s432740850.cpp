#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;
    vector<int> dx, dy;
    int cntF = 0, cntT = 0;
    for(char c : s) {
        if(c == 'F')
            cntF++;
        else {
            if(cntT == 0)
                x -= cntF;
            else if(cntF)
                (cntT & 1 ? dy : dx).push_back(cntF);
            cntT++;
            cntF = 0;
        }
    }
    if(cntT == 0)
        x -= cntF;
    else if(cntF)
        (cntT & 1 ? dy : dx).push_back(cntF);

    bitset<40000> X, Y;
    X.set(20000);
    Y.set(20000);
    for(int i : dx)
        X = (X << i) | (X >> i);
    for(int i : dy)
        Y = (Y << i) | (Y >> i);

    cout << (X[20000 + x] && Y[20000 + y] ? "Yes" : "No") << endl;

    return 0;
}