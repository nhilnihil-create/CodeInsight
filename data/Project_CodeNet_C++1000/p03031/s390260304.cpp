#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    ll N, M;
    cin >> N >> M;

    ll k[M];
    ll s[M][N];
    REP(i, M) {
        cin >> k[i];
        REP(j, k[i]) {
            cin >> s[i][j];
        }
    }

    ll p[M];
    for(ll i = 0; i < M; ++i) {
        cin >> p[i];
    }

    ll ans = 0;
    for(ll bits = 0; bits < (1 << N); ++bits) {
        bool isAllLit = true;

        for(ll i = 0; i < M; ++i) {
            ll onCnt = 0;
            for(ll j = 0; j < k[i]; ++j) {
                ll mask = 1 << (s[i][j] - 1);
                if((bits & mask) == mask) {
                    ++onCnt;
                }
            }

            if(onCnt % 2 != p[i]) {
                isAllLit = false;
                break;
            }
        }

        if(isAllLit) {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}