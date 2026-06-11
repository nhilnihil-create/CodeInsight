#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,i0,n) for(int i=i0;i<n;++i)

int main()
{
    int n;
    cin >> n;
    vector<double> t(n), v(n);
    for(auto& ti:t) cin >> ti;
    for(auto& vi:v) cin >> vi;

    vector<double> y0(n+1,0);
    double st = 0;
    rep(i,n) {
        y0[i] = v[i] + st;
        st += t[i];
    }
    y0[n] = st;

    double d = 0;
    double cv = 0;
    double ct = 0;
    double dt = 0.5;

    rep(i,n) {
        double min_y0 = 1e9;
        rep2(j,i+1,n+1) 
            min_y0 = min(min_y0, y0[j]);

        rep(j,t[i]*2) {            
            ct += dt;
            double limit = min(v[i], min_y0-ct);
            double pv = cv;
            cv = min(cv+dt, limit);
            d += (pv + cv) * dt / 2;
        }
    }

    cout << fixed << setprecision(12) << d << endl;
    return 0;
}