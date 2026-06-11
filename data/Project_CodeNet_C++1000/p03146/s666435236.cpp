#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    ll s;
    cin >> s;

    ll m = 1;
    vector<bool> has_appeared(1e6 + 5, false);
    has_appeared[s] = true;
    bool flag = false;
    while(!flag) {
        ++m;
        if(s % 2 == 0) {
            s = s / 2;
        } else {
            s = 3*s + 1;
        }

        if(has_appeared[s]) {
            flag = true;
        } else {
            has_appeared[s] = true;
        }
    }

    cout << m << endl;

    return 0;
}