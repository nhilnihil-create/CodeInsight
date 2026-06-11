#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep2(i,n) for (int i = 1; i <= (n); i++)
using ll = long long;
using Grid = vector<vector<int>>;

int main(){
    int N, M;
    cin >> N >> M;
    int lmax = 0, rmin = INT_MAX;
    rep(i,M) {
        int l,r;
        cin >> l >> r;
        lmax = max(lmax, l);
        rmin = min(rmin, r);
    }
    int ans = rmin - lmax + 1;
    if (ans < 0)
        ans = 0;
    cout << ans << endl;
}