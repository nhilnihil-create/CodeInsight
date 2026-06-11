#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<priority_queue<ll>> ques(N);
    for (int i = 0; i < N; i++) {
        int t, d;
        cin >> t >> d;
        t--;
        ques[t].push(d);
    }

    vector<ll> tops, others;
    for (auto& que : ques) {
        if (!que.empty()) {
            tops.push_back(que.top());
            que.pop();
        }
        while (!que.empty()) {
            others.push_back(que.top());
            que.pop();
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
    for (ll i = 1; i <= min((ll)K, (ll)tops.size()); i++) {
        if ((int)others.size() < K - i) {
            continue;
        }
        ll temp = i * i;
        temp += tops[i - 1];
        if (K - i - 1 >= 0) {
            temp += others[K - i - 1];
        }
        ans = max(ans, temp);
    }
    cout << ans << endl;
}
