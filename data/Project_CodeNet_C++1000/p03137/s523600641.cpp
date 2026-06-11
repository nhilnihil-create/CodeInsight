#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N, M;
int X[100100];
vector<int> d;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> M;
    rep(i, M) cin >> X[i];
    if (N>=M) {
        cout << 0 << endl;
        exit(0);
    }
    sort(X, X+M);
    rep(i, M-1) d.pb(X[i+1]-X[i]);
    sort(d.begin(), d.end());
    reverse(d.begin(), d.end());
    int sub = 0;
    rep(i, N-1) sub += d[i];
    cout << X[M-1]-X[0]-sub << endl;
}