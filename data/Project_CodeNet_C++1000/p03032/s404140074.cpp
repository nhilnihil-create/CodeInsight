#include <bits/stdc++.h>
 using namespace std;
 using pii = pair<int, int>;
 using ll = long long;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;
 const int INFI = 1000000000;
 const ll INFL = (1LL << 60);

 int main() {
    int N, K; cin >> N >> K;
    vector<ll> V(N);
    for (int i = 0; i < N; i++) cin >> V[i];

    ll res = 0;
    for (int p = 0; p <= min(K, N); p++) {
        for (int q = 0; p + q <= min(K, N); q++) {
            vector<ll> v;
            ll cur = 0;
            for (int i = 0; i < p; ++i) {
              v.push_back(V[i]);
              cur += V[i];
            }
            for (int i = 0; i < q; ++i) {
              v.push_back(V[N-1-i]);
              cur += V[N - 1 - i];
            }
            sort(v.begin(), v.end());
            for (int i = 0; i < min(K - p - q, (int)v.size()); ++i) {
                if (v[i] < 0) cur -= v[i];
            }
            res = max(res, cur);
        }
    }
    cout << res << endl;
}
