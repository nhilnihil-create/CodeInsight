#include <bits/stdc++.h>

#define INF 1e9
using namespace std;

#define REPR(i, n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()

template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


int main() {
    string S;
    cin >> S;

    // 答えのぜんれっきょ
    set<string> s;
    // 0468
    REP(i, 1 << 4) {
        // bit
        vector<bool> v(4,false);
        REP(j, 4) {
            if (1 << j & i) {
                v[j] = true;
            }
        }

        string akiba = "AKIHABARA";
        string created;
        REP(j, akiba.size()) {
            if (j == 0 && v[0]) continue;
            else if ( j == 4 && v[1]) continue;
            else if ( j == 6 && v[2]) continue;
            else if ( j == 8 && v[3]) continue;

            string ch{akiba[j]};
            created += ch;
        }
        s.insert(created);
    }

    auto ans = s.find(S) != s.end() ? "YES" : "NO";

    cout << ans << endl;

    return 0;
}
