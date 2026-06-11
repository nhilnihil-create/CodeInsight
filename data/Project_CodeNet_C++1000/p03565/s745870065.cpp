#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#ifdef RUBICK
#include "dbg.h"
#else
#define dbg(exp) /* nop; */
#endif

using namespace std;
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

int main() {
    string s, t;
    cin >> s >> t;

    auto pos = s.find(t);
    if (pos != string::npos) {
        for (auto c : s) {
            if (c == '?')
                cout << 'a';
            else
                cout << c;
        }
        cout << '\n';
        return 0;
    }

    reverse(begin(t), end(t));

    int n = s.size();

    for (int b = n-1; b >= 0; b--) {
        string ans = s;
        bool ok = true;
        for (int i = 0; i < int(t.size()); i ++) {
            if (ans[b-i] == '?' || ans[b-i] == t[i])
                ans[b-i] = t[i];
            else
                ok = false;
        }

        if (!ok)
            continue;

        for (auto c : ans) {
            if (c == '?')
                cout << 'a';
            else
                cout << c;
        }
        cout << '\n';
        return 0;
    }

    puts("UNRESTORABLE");

    return 0;
}

