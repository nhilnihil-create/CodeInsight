 #pragma GCC optimize("O3")
 #pragma GCC optimize("unroll-loops")
 #pragma GCC optimize("fast-math")
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

// #define int long long
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

void accell() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}
unordered_map<int, int>mp;
set<int>st;
void clr() {
    for (auto it : st)
        mp[it] = 0;
    st.clear();
}

bool check(int sz, vector<int>&a) {
    for (int i = 1; i < a.size(); ++i) {
        int c = a[i];
        if (c >= 5e5)
            continue;
        if (a[i - 1] >= a[i]) {
            while (st.size() > 0 && *st.rbegin() > c) {
                    mp[*st.rbegin()] = 0;
                    st.erase(*st.rbegin());
            }
            while (c >= 1 && mp[c] + 1 == sz) {
                mp[c] = 0;
                --c;
            }
            if (c == 0) {
                clr();
                return false;
            }
            mp[c]++;
            st.insert(c);
        } else {
            continue;
        }
    }
    clr();
    return true;
}


signed main() {
    accell();
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    bool ok = true;
    for (int i = 0; i + 1 < n; ++i)
        ok &= (a[i] < a[i + 1]);
    if (ok) {
        cout << 1;
        return 0;
    }
    int l = 0;
    int r = n + 1;
    while (r - l > 1) {
        int m = l + r >> 1;
        if (!check(m, a))
            l = m;
        else
            r = m;
    }
    cout << r << endl;
    return 0;
}
