#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N, A, B, C;
int l[10];

int dfs(int d, int a, int b, int c) {
    if (d==N) {
        if (min({a, b, c})>0) return abs(a-A)+abs(b-B)+abs(c-C)-30;
        else return 1000000;
    }
    int res = 1000000;
    res = min(res, dfs(d+1, a, b, c));
    res = min(res, dfs(d+1, a+l[d], b, c)+10);
    res = min(res, dfs(d+1, a, b+l[d], c)+10);
    res = min(res, dfs(d+1, a, b, c+l[d])+10);
    return res;
}

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> A >> B >> C;
    rep(i, N) cin >> l[i];
    cout << dfs(0, 0, 0, 0) << endl;
}