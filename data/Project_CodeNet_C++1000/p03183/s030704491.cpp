#include <bits/stdc++.h>

#define ll long long
#define MAXN 1005
#define MAXS 20005

using namespace std;

class item {

public:
    int w, s;
    ll v;

    item() {}
    item(int w, int s, ll v) {
        this->w = w;
        this->s = s;
        this->v = v;
    }

    bool operator<(const item &b) const {
        return (w + s < b.w + b.s);
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    item arr[n];
    for(int i = 0; i < n; i++) {
        int w, s;
        ll v;
        cin >> w >> s >> v;

        arr[i] = item(w, s, v);
    }
    sort(arr, arr + n);

    vector<ll> dp(MAXS + 1);
    for(int i = 0; i < n; i++)
        for(int j = min(arr[i].s, MAXS - arr[i].w); j >= 0; j--)
            dp[j + arr[i].w] = max(dp[j + arr[i].w], dp[j] + arr[i].v);
    
    ll ans = 0;
    for(int i = 0; i <= MAXS; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
