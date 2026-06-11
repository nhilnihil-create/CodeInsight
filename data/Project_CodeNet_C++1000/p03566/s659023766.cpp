#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int N;
    cin >> N;
    double L[N+2], R[N+2], V[N+2];
    L[0] = R[0] = V[0] = 0;
    double tm = 0;
    for(int i = 1; i <= N; ++i) {
        double t; cin >> t;
        L[i] = R[i-1];
        R[i] = L[i] + t;
        tm += t;
    }
    L[N+1] = R[N+1] = tm;
    V[N+1] = 0;
    for(int i = 1; i <= N; ++i) {
        double v; cin >> v;
        V[i] = v;
    }

    double res = 0;
    double v0 = 0, v1 = 400;
    for(int i = 1; (double)i*0.5 <= tm; ++i) {
        double x = (double)i*0.5;
        for(int j = 0; j < N+2; ++j) {
            double l = L[j], r = R[j], v = V[j];
            if(x <= l) v1 = min(v1, v + (l - x));
            else if(l <= x && x <= r) v1 = min(v1, v);
            else v1 = min(v1, v + (x - r));
        }
        res += 0.25*(v0 + v1);
        v0 = v1, v1 = 400;
    }
    cout << fixed << setprecision(10) << res << endl;
    return  0;
}