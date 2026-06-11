#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

// Copy from Uwi-san's Python
int main() {
    int N; cin >> N;
    vector T(N,0);
    rep(i,N) cin >> T.at(i);
    vector V(N,0);
    rep(i,N) cin >> V.at(i);
    vector bound(N+1, 0);
    for (int i = 0; i < N-1; i++) {
        bound[i+1] = min({V[i], V[i+1], bound[i] + T[i]});
    }
    for (int i = N-1; i > 0; i--) {
        bound[i] = min({bound[i], V[i], V[i-1], bound[i+1] + T[i]});
    }

    double ans = 0;
    rep(i, N) {
        double L = bound[i];   // Left side velocity limit
        double R = bound[i+1]; // Right side velocity limit
        // When need to break while accelerating ignoring the limit
        double x = (R - L + T[i]) / 2; // L + x = R + (T[i] - x) 
        if (L + x <= V[i]) { // breaking before (or just) touching to the limit
            // Two Trapezoid
            ans += (L + (L + x)) * x / 2 + (L + x + R) * (T[i] - x) / 2;
        } else { // Including constant speed (rectangle)
            // Two Trapezoid (both side of the area /－\) 
            // One of, or both of them can be zero (totally constant speed)
            ans += (V[i] + L) * (V[i] - L) / 2 + (V[i] + R) * (V[i] - R) / 2;
            // Rectangle (constant speed area)
            ans += (T[i] - (V[i] - L) - (V[i] - R)) * V[i];
        }
    }
    printf("%.15f\n", ans);
}