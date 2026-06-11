#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

signed main() {
    int N;
    cin >> N;
    int ans = 0;
    for(int i = 1; i*i < N; i++){
        int x = N - i;
        int m = x / i;
        if(N % m == N / m) ans += m;
    }
    cout << ans << endl;
}
