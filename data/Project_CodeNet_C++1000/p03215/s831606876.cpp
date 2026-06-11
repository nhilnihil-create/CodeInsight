#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
//#define int long long
//template<typename T> inline bool chmax(T& a,T b) { if (a < b) { a = b; return true; } return false; }
//template<typename T> inline bool chmin(T& a,T b) { if (a > b) { a = b; return true; } return false; }

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
        cin >> A[i];
        sum[i+1] = sum[i] + A[i];
    }
    
    vector<long long> B;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j <= N; j++) {
            B.emplace_back(sum[j] - sum[i]);
        }
    }
    
    
    int M = B.size();
    long long ans = 0;
    vector<bool> ok(M, true);
    
    
    for (int s = 63; s >= 0; s--) {
        long long bit = (1LL<<s);
        int cnt = 0;
        for (int i = 0; i < M; i++) if (ok[i]) {
            if (bit&B[i]) cnt++;
        }
        if (K <= cnt) {
            for (int i = 0; i < M; i++) if (ok[i]) {
                if (!(bit&B[i])) ok[i] = false;
            }
            ans += bit;
        }
    }
    
    cout << ans << endl;
    return 0;
}