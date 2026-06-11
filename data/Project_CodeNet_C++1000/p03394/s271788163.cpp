#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n;
    cin >> n;
    if (n == 3) {
        printf("2 5 63\n");
        return 0;
    }
    if (n == 4) {
        printf("2 5 20 63\n");
        return 0;
    }
    if (n == 5) {
        printf("3 5 6 8 38\n");
        return 0;
    }
    vector<ll> ans(n);
    ans[0] = 2;
    ans[1] = 3;
    ll sum = 5, idx = 2;
    reps(i, 4, 30001) {
        if ((i % 2 != 0) && (i % 3 != 0)) continue;
        sum += i;
        ans[idx++] = i;
        if (idx == n) break;
    }
    if (sum % 6 != 0) {
        ll rem = 6 - sum % 6;
        rrep(i, n) {
            if (((ans[i] + rem) % 2 == 0) || ((ans[i] + rem) % 3 == 0)) {
                ans[i] += rem;
                rem = 0;
            }
            else {
                ans[i] += (rem - 1);
                rem = 1;
            }
            if (rem == 0) break;
        }
    }
    rep(i, n) printf("%lld%s", ans[i], (i == (n - 1)) ? "\n" : " ");
    return 0;
}
