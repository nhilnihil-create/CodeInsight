#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double Double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// chmax, chmin
template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

void solve(long long N, long long K, std::vector<long long> a) {
    vector<long long> S;
    for (int i = 0; i < N; i++) {
        long long sum = 0;
        for (int j = i; j < N; j++) {
            sum += a[j];
            S.push_back(sum);
        }
    }

    sort(S.rbegin(), S.rend());
    long long ans = 0;
    for (int j = 42; j >= 0; j--) {
        int cnt = 0;
        int lst = 0;
        for (int k = 0; k < S.size(); k++) {
            if (S[k] >> j & 1) {
                cnt++;
                lst = k;
            }
        }
        if (cnt >= K) {
            ans += (1ll<<j);
            S.resize(lst + 1);
        } else {
            for (int k = 0; k < S.size(); k++) {
                S[k] &= ~(1ll << j);
            }
        }
        sort(S.rbegin(), S.rend());
    }
    cout << ans << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    long long K;
    scanf("%lld", &K);
    std::vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
    }
    solve(N, K, std::move(a));
    return 0;
}
