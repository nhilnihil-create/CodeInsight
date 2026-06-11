#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, Q; cin >> A >> B >> Q;
    vector<long long> shrine(A); for (auto &x : shrine) cin >> x;
    vector<long long> temple(B); for (auto &x : temple) cin >> x;
    while (Q--) {
        long long x; cin >> x;
        long long ls, rs;
        if (shrine[0] > x) {
            ls = -1, rs = shrine[0] - x;
        } else if (shrine[A-1] < x) {
            ls = x - shrine[A-1], rs = -1;
        } else {
            int ok = 0, ng = A;
            while (ng - ok != 1) {
                int med = (ok + ng) / 2;
                if (shrine[med] < x) ok = med;
                else ng = med;
            }
            ls = x - shrine[ok], rs = shrine[ng] - x;
        }
        long long lt, rt;
        if (temple[0] > x) {
            lt = -1, rt = temple[0] - x;
        } else if (temple[B-1] < x) {
            lt = x - temple[B-1], rt = -1;
        } else {
            int ok = 0, ng = B;
            while (ng - ok != 1) {
                int med = (ok + ng) / 2;
                if (temple[med] < x) ok = med;
                else ng = med;
            }
            lt = x - temple[ok], rt = temple[ng] - x;
        }
        long long ans = 1e12;
        if (ls != -1 && lt != -1) ans = min(ans, max(ls, lt));
        if (rs != -1 && rt != -1) ans = min(ans, max(rs, rt));
        if (ls != -1 && rt != -1) ans = min(ans, (min(ls, rt) * 2 + max(ls, rt)));
        if (lt != -1 && rs != -1) ans = min(ans, (min(lt, rs) * 2 + max(lt, rs)));
        cout << ans << endl;
    }
}
