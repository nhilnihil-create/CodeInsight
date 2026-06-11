#include <bits/stdc++.h>
using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    int ban = (n%2 ? n : n+1);

    vector<pair<int,int>> ans;
    for (int u = 1; u <= n; u++) {
        for (int v = u+1; v <= n; v++) {
            if (u+v != ban) ans.emplace_back(u,v);
        }
    }
    cout << ans.size() << '\n';
    for (auto uv : ans) {
        int u,v; tie(u,v) = uv;
        cout << u << ' ' << v << '\n';
    }
    
    return 0;
}
