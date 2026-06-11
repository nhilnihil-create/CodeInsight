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
    string S;
    cin >> S;

    bool flag = true;

    if(S[0] != 'A') {
        flag = false;
    }

    bool has_C = false;
    ll ci;
    for(ll i = 2; i < S.length() - 1; ++i) {
        if(!has_C) {
            if(S[i] == 'C') {
                has_C = true;
                ci = i;
            }
        } else {
            if(S[i] == 'C') {
                has_C = false;
                break;
            }
        }
    }
    if(!has_C) {
        flag = false;
    }

    if(flag) {
        REP(i, S.length()) {
            if(i != 0 && i != ci && !(S[i] >= 'a' && S[i] <= 'z')) {
                flag = false;
                break;
            }
        }
    }

    if(flag) {
        cout << "AC" << endl;
    } else {
        cout << "WA" << endl;
    }

    return 0;
}