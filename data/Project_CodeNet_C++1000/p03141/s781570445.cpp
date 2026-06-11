#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

struct dish {
    ll a, b;
    dish(ll a, ll b):a(a), b(b) {}
    bool operator<(const dish& d) {
        return a + b > d.a + d.b;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<dish> D;
    ll A, B;
    rep(i, 0, N) {
        cin >> A >> B;
        D.emplace_back(A, B);
    }
    sort(all(D));
    ll ans = 0;
    rep(i, 0, N) {
        if (i % 2 == 0) {
            ans += D[i].a;
        }
        else {
            ans -= D[i].b;
        }
    }
    cout << ans << endl;
    return 0;
}