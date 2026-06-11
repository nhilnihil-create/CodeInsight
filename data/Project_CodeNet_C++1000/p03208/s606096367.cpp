#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define inf 1e9
#define INF 1000000000000000000

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> h(N);
    rep(i, N) { cin >> h[i]; }
    sort(all(h));
    int left = 0, right = K - 1;
    int ans = inf;
    while (right >= 0 && right < N) {
        ans = min(ans, h[right] - h[left]);
        right++, left++;
    }

    cout << ans << endl;
}