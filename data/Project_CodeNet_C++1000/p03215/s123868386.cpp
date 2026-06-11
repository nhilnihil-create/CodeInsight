#include <bits/stdc++.h>
using namespace std;

long long POW(long long x, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 1) return (x * POW(x, n - 1));
    long long t = POW(x, n / 2);
    return (t * t);
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    vector<long long> sum(N+1, 0);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
        sum[i+1] = sum[i] + A[i];
    }
    
    vector<long long> B;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j <= N; j++) {
            B.emplace_back(sum[j]-sum[i]);
        }
    }
    
    vector<bool> ok(B.size(), true);
    long long ans = 0;
    long long t = POW(2LL, 40LL);
    int s = 40;
    while (t > 0) {
        int cnt = 0;
        for (int i = 0; i < (int)B.size(); i++) if (ok[i]) {
            if (B[i]&t) cnt++;
        }
        if (K <= cnt) {
            ans += (1LL<<s);
            for (int i = 0; i < (int)B.size(); i++) if (ok[i]) {
                if (!(B[i]&t)) B[i] = false;
            }
        }
        t /= 2;
        s--;
    }
    
    cout << ans << '\n';
    return 0;
}