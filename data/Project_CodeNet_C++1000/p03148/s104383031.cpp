#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<priority_queue<ll>> S(N);
    for (int i = 0; i < N; i++) {
        int t;
        ll d;
        cin >> t >> d;
        t--;
        S[t].push(d);
    }
    vector<ll> tops;
    vector<ll> others;
    int T = 0;
    for (int i = 0; i < N; i++) {
        if (S[i].empty()) {
            continue;
        }
        T++;
        tops.push_back(S[i].top());
        S[i].pop();
        while (!S[i].empty()) {
            others.push_back(S[i].top());
            S[i].pop();
        }
    }

    sort(tops.begin(), tops.end(), greater<ll>());
    sort(others.begin(), others.end(), greater<ll>());
    for (int i = 1; i < (int)tops.size(); i++) {
        tops[i] += tops[i - 1];
    }
    for (int i = 1; i < (int)others.size(); i++) {
        others[i] += others[i - 1];
    }

    ll ans = 0;
    for (ll k = 1; k <= min(T, K); k++) {
        if (K - k - 1 >= (int)others.size()) {
            continue;
        }
        ll sum = k * k + tops[k - 1];
        if (k == K) {
            sum += 0;
        } else {
            sum += others[K - k - 1];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}
