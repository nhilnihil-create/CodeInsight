#include <bits/stdc++.h>
using namespace std;
#define dump(x) cout << (x) << '\n';
#define all(x) x.begin(), x.end()
#define fi first
#define se second
typedef int64_t Int;
Int mod = 1e9+7;
Int INF = 1e9+7;

int main() {
    Int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<char> t(q), d(q);
    for (Int i = 0; i < q; i++) {
        cin >> t[i] >> d[i];
    }
    Int ok = -1;
    Int ng = n;
    while (abs(ok - ng) > 1)  {
        Int mid = (ok + ng) / 2;
        bool check = false;
        Int cur = mid;
        for (Int i = 0; i < q; i++) {
            if (t[i] != s[cur]) continue;
            if (d[i] == 'L') {
                cur--;
                if (cur < 0) {
                    check = true;
                    break;
                }
            }
            else {
                cur++;
                if (cur == n) {
                    break;
                }
            }
        }
        if (check) {
            ok = mid;
        }
        else {
            ng = mid;
        }
    }
    Int left = ok + 1;
    ok = n;
    ng = -1;
    while (abs(ok - ng) > 1)  {
        Int mid = (ok + ng) / 2;
        bool check = false;
        Int cur = mid;
        for (Int i = 0; i < q; i++) {
            if (t[i] != s[cur]) continue;
            if (d[i] == 'L') {
                cur--;
                if (cur < 0) {
                    break;
                }
            }
            else {
                cur++;
                if (cur == n) {
                    check = true;
                    break;
                }
            }
        }
        if (check) {
            ok = mid;
        }
        else {
            ng = mid;
        }
    }
    Int right = n - ok;
    dump(n - (left + right));
    return 0;
}