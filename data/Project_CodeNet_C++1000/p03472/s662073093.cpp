#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, H;
    cin >> N >> H;
    vector<pair<ll, ll>> A;
    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        A.push_back({a, (ll)0});
        A.push_back({b, (ll)1});
    }

    sort(all(A),
         [](pair<ll, ll> a, pair<ll, ll> b) { return a.first > b.first; });

    ll cnt = 0;
    rep(i, A.size()) {
        if (A[i].second == 1)
            H -= A[i].first, cnt++;
        else {
            if (H % A[i].first == 0) {
                cnt += (H / A[i].first);
            } else {
                cnt += (H / A[i].first) + 1;
            }
            break;
        }
        if (H <= 0)
            break;
    }

    cout << cnt << endl;
}
