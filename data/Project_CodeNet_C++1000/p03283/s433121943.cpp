#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> ii;

const int N = 500 + 5;
int n, m, q, c, a[N][N];

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        a[l][r]++;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            a[i][j] = a[i][j] + a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
    }
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << a[n][r] - a[l - 1][r] << "\n";
    }
}
