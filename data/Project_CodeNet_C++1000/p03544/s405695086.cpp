#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const int INF = 1000100100;

vector<ll> memo(87, -1);

ll L(ll i) {
    if(memo[i] != -1) {
        return memo[i];
    }

    if(i == 0) {
        memo[i] = 2;
    } else if(i == 1) {
        memo[i] = 1;
    } else {
        memo[i] = L(i - 1) + L(i - 2);
    }

    return memo[i];
}

int main() {
    ll N;
    cin >> N;
    cout << L(N) << endl;

    return 0;
}