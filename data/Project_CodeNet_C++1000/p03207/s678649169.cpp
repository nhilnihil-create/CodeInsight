#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int N; cin >> N;
    int P[10]; rep(i, N) cin >> P[i];
    sort(P, P + N);
    int ans = 0;
    rep(i, N) ans += P[i] / 2;
    rep(i, N - 1) ans += P[i] / 2;
    cout << ans << endl;

    return 0;
}