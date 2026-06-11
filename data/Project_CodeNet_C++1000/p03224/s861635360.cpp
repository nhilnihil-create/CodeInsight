#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define pb push_back
#define ppp pop_back
#define fi first
#define se second
#define pii pair<int,int>

const int N = 1e5 + 5;

int a[N];
int b[500][N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    for (int i=1; i<N; i++) a[i] = 0;
    for (int k=2; k*(k-1)/2 < N; k++) a[k*(k-1)/2] = k;
    if (a[n]) {
        int k = a[n];
        for (int i=1; i<=k; i++) {
            for (int j=1; j<=n; j++) {
                b[i][j] = 0;
            }
        }
        int col = 1;
        for (int i=1; i<=k-1; i++) {
            for (int j=i+1; j<=k; j++) {
                b[i][col] = 1;
                b[j][col] = 1;
                col++;
            }
        }
        cout << "Yes\n";
        cout << k << "\n";
        for (int i=1; i<=k; i++) {
            cout << k-1 << " ";
            for (int j=1; j<=n; j++) {
                if (b[i][j]) cout << j << " ";
            }
            cout << "\n";
        }
    }

    else cout << "No\n";
    return 0;
}
