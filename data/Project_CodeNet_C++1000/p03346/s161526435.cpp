#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> P(N);
    vector<pll> p(N);
    rep(i, N) {
        cin >> P[i];
        p[i] = {P[i], i};
    }

    sort(all(p));

    int right = 0, cnt = 1;
    int ans = 0;
    while (right < N - 1) {
        if (p[right].second <= p[right + 1].second) {
            cnt++;
        } else {
            ans = max(ans, cnt);
            cnt = 1;
        }
        right++;
    }
    ans = max(ans, cnt);

    cout << N - ans << endl;
}