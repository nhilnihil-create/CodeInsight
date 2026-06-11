#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using pll = pair<ll,ll>;
using vll = vector<pll>;

#define COUNT first
#define CHAR  second

bool check(ll X, const vl& A) {
    ll N = A.size(), last = 0;
    vll s(N, pll(0, 0));
    for (int i = 1; i < N; ++i) {
        ll diff = A[i] - A[i-1];
        // a < b  : push_back 0 * (b - a)
        if (diff > 0) {
            if (s[last].CHAR == 0) {
                s[last].COUNT += diff;
            } else {
                s[last+1] = make_pair(diff, 0);
                last++;
            }
        } else {
        // a >= b : pop_back (b - a)
            diff = -diff;
            while (true) {
                if (s[last].COUNT < diff) {
                    diff -= s[last].COUNT;
                    s[last].COUNT = 0;
                    last--;
                } else {
                    s[last].COUNT -= diff;
                    if (s[last].COUNT == 0) last--;
                    break;
                }
            }
        //              and inclement the last element
            bool ng = true;
            for (int l = 0; l <= last; ++l) {
                if (s[l].CHAR != X-1) ng = false;
            }
            if (ng) return false;

            ll cnt = 0;
            while (s[last].CHAR == X-1) {
                cnt += s[last].COUNT;
                last--;
            }
            if (s[last].COUNT == 1) {
                s[last].CHAR++;
            } else {
                s[last].COUNT--;
                s[last+1] = make_pair(1, s[last].CHAR+1);
                last++;
            }
            if (cnt) s[++last] = make_pair(cnt, 0);
        }
    }
    return true;
}

int main() {
    ll N; cin >> N;
    vl A(N+1,0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i+1];
    }

    ll ok = 1e9, ng = 0;
    while (ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid, A)) {
            ok = mid;
        } else  {
            ng = mid;
        }
    }
    cout << ok << endl;
    return 0;
}

