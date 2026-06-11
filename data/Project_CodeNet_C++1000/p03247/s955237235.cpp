#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<ll> X(N), Y(N);
    vector<ll> a(N), b(N);
    bool odd = false, even = false;
    rep(i, N) {
        cin >> X[i] >> Y[i];
        (X[i] + Y[i] & 1 ? odd : even) = true;
        if(even) Y[i]--; //奇数の場合に帰着 最後に1,Uすればよい
        a[i] = X[i] + Y[i];
        b[i] = X[i] - Y[i];
    }
    if(odd && even) {
        cout << -1 << endl;
        return 0;
    }
    cout << 31 + even << endl;
    for(int i = 30; i >= 0; i--)
        cout << (1 << i) << " ";
    if(even) cout << 1;
    cout << endl;

    string s = "LDUR";
    rep(i, N) {
        string ans;
        ll nowa = 0, nowb = 0;
        for(int j = 30; j >= 0; j--) {
            int A, B;
            nowa += ((A = (nowa < a[i])) ? 1 : -1) << j;
            nowb += ((B = (nowb < b[i])) ? 1 : -1) << j;
            ans.push_back(s[2 * A + B]);
        }
        cout << ans;
        if(even) cout << "U";
        cout << endl;
    }

    return 0;
}