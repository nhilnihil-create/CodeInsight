#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1000100100;

int main() {
    vector<ll> dishes(5);
    REP(i, 5) {
        cin >> dishes[i];
    }

    vector<ll> order(5);
    REP(i, 5) {
        order[i] = i;
    }

    ll ans = INF;
    do {
        ll time = 0;
        REP(i, 5) {
            if(time % 10 != 0) {
                time += 10 - (time % 10);
            }
            time += dishes[order[i]];
        }
        if(time < ans) {
            ans = time;
        }
    } while(next_permutation(order.begin(), order.end()));

    cout << ans << endl;

    return 0;
}