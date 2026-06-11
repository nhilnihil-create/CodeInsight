
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

template <typename T>
void print(T x) {
    cout << x << endl;
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string S, T;
    cin >> S >> T;

    if (S == T) {
        print("Yes");
        return 0;
    }

    unordered_map<char, char> m;

    REP(i, S.size()) {
        if (m.find(S[i]) == m.end()) {
            m[S[i]] = T[i];
        } else {
            if (m[S[i]] != T[i]) {
                print("No");
                return 0;
            }
        }
    }

    set<char> open;

    vector<bool> v(30, false);

    for(auto &p: m) {
        char start = p.fi;

        if (open.count(start) > 0) continue;

        char to = p.se;

        open.insert(start);

        while(true) {
            if (to == start) {
                break; // ok
            }

            if (open.count(to) > 0) {
                if (v[to - 'a']) {
                    // ok
                    v[start - 'a'] = true;
                    v[to - 'a'] = false;
                    break;
                }

                // ng
                print("No");
                return 0;
            }

            open.insert(to);

            if (m.find(to) == m.end()) {
                v[start - 'a'] = true;
                break; //ok
            }

            to = m[to];
        }
    }

    print("Yes");

}
