#include <bits/stdc++.h>
using namespace std;
#define INF 1001001001

int main() {
    int N;
    cin >> N;
    vector<int> t(N+3);
    t[0] = t[1] = 0;
    for(int i=1; i<=N; ++i) {
        int tmp; cin >> tmp;
        t[i+1] = t[i] + tmp;
    }
    t[N+2] = t[N+1];
    vector<int> v(N+2);
    v[0] = 0;
    for(int i=1; i<=N; ++i) cin >> v[i];
    v[N+1] = 0;

    int tmax = t[N+2];
    vector<double> v2(2 * tmax + 1, INF);
    for(int i=0; i<=N+1; ++i) {
        for(int tm=0; tm<=2*tmax; ++tm) {
            if(0.5 * tm < t[i]) {
                v2[tm] = min(v2[tm], v[i] + t[i] - 0.5 * tm);
            } else if(0.5 * tm > t[i+1]) {
                v2[tm] = min(v2[tm], v[i] + 0.5 * tm - t[i+1]);
            } else {
                v2[tm] = min(v2[tm], (double)v[i]);
            }
        }
    }

    double ans = 0;
    for(int tm=0; tm<2*tmax; ++tm) {
        ans += 0.25 * (v2[tm] + v2[tm+1]);
    }
    printf("%.4f\n", ans);
    return 0;
}