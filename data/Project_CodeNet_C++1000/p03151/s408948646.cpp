#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    ll N; cin >> N;
    vector<ll> A(N), B(N);
    rep(i,N) cin >> A.at(i);
    vector<pair<ll, ll>> plus, minus;
    ll sump = 0, summ = 0;
    rep(i,N) {
        cin >> B.at(i);
        if (B[i] > A[i]) {
            ll d = B[i] - A[i];
            minus.push_back({d, i});
            summ += d;
        } else {
            ll d = A[i] - B[i];
            plus.push_back({d, i});
            sump += d;
        }
    }
    if (plus.size() == N) {
        cout << 0 << endl;
        return 0;
    } else if (sump < summ) {
        cout << -1 << endl;
        return 0;
    }

    sort(plus.begin(), plus.end(), greater<pair<ll,ll>>());
    sort(minus.begin(), minus.end());

    ll i = 0, cnt = 0;
    while (!minus.empty()) {
        cnt++;
        ll m = minus.back().first; minus.pop_back();
        while (plus[i].first <= m) {
            m -= plus[i].first;
            i++;
        }
        plus[i].first -= m;
    }
    cout << i + cnt + 1 << endl;
}
