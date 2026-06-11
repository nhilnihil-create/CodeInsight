#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
double T;
/* function */
double calcMaxV(double l, double r, double x, double v) {
    if (0 <= x && x <= l) return v + (l - x);
    else if (l <= x && x <= r) return v;
    else if (r <= x && x <= T) return v + (x - r);
    return v + (x - r);
}
/* main */
int main(){
    int N;
    cin >> N;
    vector<double> v(N+2), t(N+2);
    for (int i = 1; i <= N; i++) cin >> t[i];
    for (int i = 1; i <= N; i++) cin >> v[i];
    T = accumulate(t.begin(), t.end(), 0);
    v[0] = 0;
    v[N+1] = 0;
    t[0] = 0;
    t[N+1] = T;
    vector<pdd> p(N+2);
    p[0] = pdd(0, 0);
    for (int i = 0; i < N; i++) { p[i+1] = pdd(p[i].second, p[i].second+t[i+1]); }
    p[N+1] = pdd(T, T);
    double D = 0.0;
    double vst = 0.0;
    for (double a = 0.0; a < T; a += 0.5) {
        double maxV = INF;
        for (int i = 0; i < N+2; i++) {
            maxV = min(maxV, calcMaxV(p[i].first, p[i].second, a+0.5, v[i]));
        }
        D += 0.25 * (vst + maxV);
        vst = maxV;
    }

    cout << setprecision(10) << D << '\n';
}