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

int N;
vector<int> A;

bool f(const int &x) {
    if(x <= 0) return false;
    int len = 0;
    map<int, int> mp;
    for(int a : A) {
        if(len >= a) {
            mp.erase(mp.upper_bound(a), mp.end());
            if(x <= 1) return false;
            int pos = a;
            while(mp[pos] == x - 1) {
                mp.erase(pos);
                pos--;
            }
            if(pos <= 0) return false;
            mp[pos]++;
        }
        len = a;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];

    int ng = 0, ok = N;
    while(ng + 1 < ok)
        (f(ng + ok >> 1) ? ok : ng) = ng + ok >> 1;
    cout << ok << endl;

    return 0;
}