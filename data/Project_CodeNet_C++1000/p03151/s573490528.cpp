#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep2l(i, s, n) for (ll i = (ll)(s); i < (ll)n; i++)

int main() {
    int N;
    cin >> N;
    vector<vector<ll>> pre(2, vector<ll>(N));
    rep(i, N) {
        ll A;
        cin >> A;
        pre[0][i] = A;
    }
    rep(i, N) {
        ll B;
        cin >> B;
        pre[1][i] = B;
    }
    ll lack = 0;
    ll over = 0;
    priority_queue<ll> lacks;
    priority_queue<ll> overs;
    vector<ll> C(N);
    rep(i, N) {
        ll c = pre[0][i]-pre[1][i];
        if (c < 0) {
            lack -= c;
            lacks.push(c);
        }
        if (c > 0) {
            over += c;
            overs.push(c);
        }
        C[i] = c;
    }
    if (lack > over) {
        cout << -1 << endl;
        return 0;
    }
    int ans = lacks.size();
    while(lack > 0) {
        lack -= overs.top();
        overs.pop();
        ans++;
    }
    cout << ans << endl;
}