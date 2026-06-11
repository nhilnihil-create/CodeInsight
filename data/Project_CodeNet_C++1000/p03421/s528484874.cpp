#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n, a, b;
    cin >> n >> a >> b;
    if (a + b - 1 <= n && n <= a * b) {
        for (int i = b; i >= 1; --i) cout << i << ' ';
        int h = n - a - b + 1;
        int ptr = b + 1;
        for (int i = 0; i < a - 1; ++i) {
            int sz = 1 + min(h, b - 1);
            h -= min(h, b - 1);
            for (int j = ptr + sz - 1; j >= ptr; --j) cout << j << ' ';
            ptr += sz;
        }   
        cout << '\n';
    }
    else {
        cout << "-1\n";
    }   

}   