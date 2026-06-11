#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,r;
    cin >> n >> m >> r;
    vector<vector<int>> st(n);
    for(int i = 0; i < m; i++) {
        int l,r;
        cin >> l >> r;
        st[l-1].emplace_back(r-1);
    }
    for(int i = 0; i < n; i++) {
        sort(st[i].begin(),st[i].end());
    }

    for(int i = 0; i < r; i++) {
        int p,q;
        cin >> p >> q;
        int cnt=0;
        for(int j = p-1; j < q; j++) {
            int add=lower_bound(st[j].begin(),st[j].end(),q) - st[j].begin();
            cnt+=add;
        }
        cout << cnt << "\n";
    }

    return 0;
}