#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // std::ifstream in("input.txt");
    // std::cin.rdbuf(in.rdbuf());
    ll m, k;
    cin >> m >> k;
    if (k >= (1 << m)) {
        cout << "-1" << endl;
    }
    else if (m == 0) {
        if (k == 0) cout << "0 0" << endl;
        else cout << "-1" << endl;
    }
    else if (m == 1) {
        if (k == 0) cout << "0 0 1 1" << endl;
        else cout << "-1" << endl;
    }
    else {
        set<ll> s;
        rep(i, 1 << m) s.insert(i);
        deque<ll> dq;
        dq.push_back(k);
        s.erase(k);
        for(auto x : s) {
            dq.push_front(x);
            dq.push_back(x);
        }
        dq.push_back(k);
        rep(i, sz(dq)) {
            printf("%lld%s", dq[i], (i == (sz(dq) - 1)) ? "\n" : " ");
        }
    }
    return 0;
}
