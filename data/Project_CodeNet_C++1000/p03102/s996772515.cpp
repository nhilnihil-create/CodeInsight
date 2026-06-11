#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < b; i++)
int main() {
    int N, M, C;
    cin >> N >> M >> C;

    int a[21][21];
    int b[21];
    rep(i, 0, M) { cin >> b[i]; }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    ll sum = 0;
    for(int i = 0; i < N; i++) {
        sum = 0;
        for(int j = 0; j < M; j++) {
            sum += b[j] * a[i][j];
        }
        if(sum + C > 0) {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
