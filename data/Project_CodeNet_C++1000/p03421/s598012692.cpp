#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <deque>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll SIZE = 1e6 + 10, S2 = 1e7 * 2, MOD = 1e9 + 7, INF = 1e9 * 1e9 + 100;

ll check(ll vl, ll a, ll b) {
    /*vector<ll> vec1, vec2;
    for (int i = 1; i <= vl; i++) {
        if (i != a) vec1.push_back(i);
    }

    for (int i = 1; i <= vl; i++) {
        if (i != b) vec2.push_back(i);
    }
    if (vec1.size() < vl) vec1.push_back(vl + 1);
    if (vec2.size() < vl) vec2.push_back(vl + 1);
*/
    ll q = 0;
    ll q2 = 0, vl1 = (vl - 1) / 2, vl2 = (vl - 1) / 2;

    if (vl == 14) {
        cout << "";
    }
    if (vl % 2 != 0) {
        vl1 = (vl / 2) + 1;
        vl2 = vl1;
        if (vl1 >= a) vl1++;
        if (vl2 >= b) vl2++;
        q2 = vl1 * vl2;
    }
    else {
        vl1 = (vl - 1) / 2 + 1, vl2 = vl1 + 1;
        if (vl1 >= a) vl1++;
        if (vl2 >= b) vl2++;
        if (vl2 < b) {
            ll q = b - vl2, v1 = vl1, v2 = vl2;
            v1 -= q;
            v2 = b + 1;
            q2 = v2 * v1;
        }
        if (vl1 < a) {
            ll q = a - vl1, v1 = vl1, v2 = vl2;
            v1 = a + 1;
            v2 -= q;
            q2 = max(v2, v2 * v1);
        }
        q2 = max(q2, vl2 * vl1);
        vl1 = (vl - 1) / 2 + 1, vl2 = vl1 + 1;
        vl1--;
        //if (vl2 < b) {
        //    ll q = b - vl2, v1 = vl1, v2 = vl2;
        //    v1 -= q;
        //    v2 = b + 1;
        //    q2 = v2 * v1;
        //}
        //if (vl1 < a) {
        //    ll q = a - vl1, v1 = vl1, v2 = vl2;
        //    v1 = a + 1;
        //    v2 -= q;
        //    q2 = max(v2, v2 * v1);
        //}
        if (vl1 >= a) vl1++;
        if (vl2 >= b) vl2++;
        
        q2 = max(q2, vl2 * vl1);
    }

   /* for (int i = 0; i < vl; i++) q = max(q, vec1[i] * vec2[vl - i - 1]);
*//*
    if (q != q2) {
        cout << "sdhfb";
    }*/
    q = q2;
    return q;
}

int main() {
    fastInp;

    ll n, a, b;
    cin >> n >> a >> b;

    if (a + b > n + 1) {
        cout << "-1";
        return 0;
    }

    vector<ll> perm;
    set<ll> vals;
    for (int i = 0; i < n; i++) {
        vals.insert(i + 1);
    }
    ll ch = 0, pr = 0, pr2 = 0;
    if (a < b) ch = 1;
    bool fl1 = (a == 1), fl2 = (b == 1);
    while (!vals.empty()) {
        if (ch == 0) {
            vector<ll> cur;
            fl1 = true;
            if (a - pr == 0 && vals.size() != 0) {
                cout << "-1";
                return 0;
            }
            for (int i = 0; i < a - pr; i++) {
                if (vals.size() == 0) continue;
                cur.push_back(*vals.rbegin());
                vals.erase(--vals.end());
            }
            reverse(cur.begin(), cur.end());
            for (auto c : cur) perm.push_back(c);
            pr2++;
        }
        else {
            fl2 = true;
            vector<ll> cur;
            if (b - pr2 == 0 && vals.size() != 0) {
                cout << "-1";
                return 0;
            }
            for (int i = 0; i < b - pr2; i++) {
                if (vals.size() == 0) continue;
                cur.push_back(*vals.begin());
                vals.erase(vals.begin());
            }
            reverse(cur.begin(), cur.end());
            for (auto c : cur) perm.push_back(c);
            pr++;
        }
        ch = !ch;
    }

    if (!fl1 || !fl2) {
        cout << "-1";
        return 0;
    }
    for (auto c : perm) cout << c << " ";
    return 0;
}

