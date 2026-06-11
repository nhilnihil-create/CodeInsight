#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,X;
    cin >> N >> X;
    vector<int>x(N);
    for(int i = 0; i < N; i++) {
        cin >> x[i];
        x[i] = abs(x[i]-X);
    }
    int ans = x[0];
    for(int i = 0; i < N; i++) {
        ans = __gcd(ans,x[i]);
    }
    cout << ans << endl;
}