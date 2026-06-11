#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<ll> a(N), b(N);
    REP(i, N) cin >> a[i];
    REP(i, N) cin >> b[i];
    ll cnt = 0;
    REP(i, N) {
        if (a[i] < b[i]) {
            ll c = (b[i] - a[i] + 1) / 2;
            a[i] += c * 2;
            cnt += c;
        }
        if (a[i] > b[i]) {
            cnt -= a[i] - b[i];
        }
    }
    cout << (cnt >= 0 ? "Yes" : "No") << endl;
}