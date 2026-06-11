#include <bits/stdc++.h>

#define rep(i, N) for (ll i = 0; i < N; i++)
#define rep1(i, N) for (ll i = 1; i <= N; i++)
#define MOD (int)1e9+7;

using ll = long long;
using namespace std;

int main() {
    int N;
    cin >> N;
    int cnt[(int)1e5+3] = {0};
    int ans = 0;

    rep(i, N) {
        int a;
        cin >> a;
        if(a > N) ans++;
        else cnt[a]++;
    }
    
    rep1(i, N) {
        if(cnt[i] > i) ans += cnt[i] - i;
        else if(cnt[i] < i) ans += cnt[i];
    }

    cout << ans << "\n";
    return 0;
}
