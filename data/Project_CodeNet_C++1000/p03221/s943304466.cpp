#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1000100100;

int main() {
    ll N, M;
    cin >> N >> M;

    vector<ll> IDs(M, 0);
    vector<vector<pair<ll, ll>>> P_years(N + 1);
    REP(i, M) {
        ll P, Y;
        cin >> P >> Y;
        P_years.at(P).emplace_back(make_pair(Y, i));
    }

    REP(pi, P_years.size()) {
        sort(P_years.at(pi).begin(), P_years.at(pi).end());

        REP(yi, P_years.at(pi).size()) {
            ll i = P_years.at(pi).at(yi).second;
            IDs[i] += pi * 10e5;
            IDs[i] += yi + 1;
        }
    }

    REP(i, IDs.size()) {
        printf("%012lld\n", IDs[i]);
    }

    return 0;
}