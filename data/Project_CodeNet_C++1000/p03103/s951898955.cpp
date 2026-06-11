#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define rep(i, N) for (ll i = 0; i < (N); i++)
#define FOR(i, a, b) for (ll i = (a), i < (N): i++)
// #define all(A) A.begin(),A.end()

int main(){
    int N, M;
    cin >> N >> M;
    vector<pll> AB(N);
    rep(i, N) {
        cin >> AB[i].first >> AB[i].second; 
    }
    sort(AB.begin(), AB.end());
    ll ans = 0;
    int i = 0;
    while (true) {
        if (AB[i].second >= M) {
            ans += M * AB[i].first;
            cout << ans << endl;
            return 0;
        }
        else {
            M -= AB[i].second;
            ans += AB[i].first * AB[i].second;
            i++;
        }

    }

    return 0;
}
