#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, N) for (ll i = 0; i < (N); i++)
#define For(i, a, b) for (ll i = (a); i < (b); i++)
#define all(A) (A).begin(), (A).end()

int main(){
    ll N, M;
    cin >> N >> M;
    vector<pll> AB(N);
    rep(i, N) {
        cin >> AB[i].first >> AB[i].second;
    }
    sort(all(AB));

    ll ans = 0;
    rep(i, N) {
        if (AB[i].second >= M) {
            ans += AB[i].first * M;
            cout << ans << endl;
            return 0;
        }
        else {
            ans += AB[i].first * AB[i].second;
            M -= AB[i].second;
        }
    }
    return 0;
}
