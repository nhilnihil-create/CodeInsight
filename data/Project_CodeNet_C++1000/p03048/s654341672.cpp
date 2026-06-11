#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i <= n; i++)
#define ll long long
using namespace std;



int main() {
    int R, G, B, N; cin >> R >> G >> B >> N;
    int ans = 0;
    rep(i, 3000) rep(j, 3000)
        if ((N - (i*R+j*G)) % B == 0 && (N - (i*R+j*G)) >= 0) ans++;
    cout << ans << endl;
    return 0;
}
