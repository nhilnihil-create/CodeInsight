#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL mod = 1e9+7;

double calc(double vi, double t, double ts, double dt) {
    if(t < ts){
        return vi + ts - t;
    }else if(ts + dt < t){
        return vi + t - (ts + dt);
    }else{
        return vi;
    }
}

int main() {
    int N;
    cin >> N;
    vector<double> t(N + 2, .5);
    FOR(i, 1, N + 1) {
        cin >> t[i];
    }
    vector<double> v(N + 2, 0);
    FOR(i, 1, N + 1) {
        cin >> v[i];
    }
    int M = 2*accumulate(ALL(t), (double)0);
    vector<double> res(M, 334);
    res[M - 1] = 0;
    res[0] = 0;
    FOR(i, 1, M - 1) {
        double st = -0.5;
        for(int j = 0;j < N + 2;j++) {
            res[i] = min(res[i], calc(v[j], (double)(i - 1)/2, (double)st, (double)t[j]));
            st += (double)t[j];
        }
    }
    vector<double> d(M, 0);
    FOR(i, 1, M - 1) {
        d[i] = (res[i] + res[i + 1])/4;
    }
    double y = accumulate(ALL(d), (double)0);
    printf("%.9lf\n", y);
    return 0;
}
