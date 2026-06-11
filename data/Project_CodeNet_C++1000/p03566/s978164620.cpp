#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<double, double>;

int main() {
    int n;
    cin >> n;
    vector<int> t(n+1, 0);
    vector<double> v(n+2, 0);
    rep(i, n) cin >> t[i+1];
    rep(i, n) cin >> v[i+1];

    rep(i, n)t[i+1] += t[i];
    vector<vector<P>> u(n);
    rep(i, n){
        u[i].push_back(make_pair(1.0, 0.0));
        u[i].push_back(make_pair(-1.0, t[n]));
        rep(j, n){
            if(j < i)u[j].push_back(make_pair(-1.0, v[i+1]+t[i]));
            else if(j==i)u[j].push_back(make_pair(0.0, v[i+1]));
            else u[j].push_back(make_pair(1.0, v[i+1]-t[i+1]));
        }
    }

    ld d = 0;
    double bv = 0.0;
    rep(i, n){
        for(double j = t[i]+0.5; j <= t[i+1]+1e-6; j += 0.5){
            double vv = 10000.0;
            rep(k, n+2)vv = min(vv, u[i][k].first * j + u[i][k].second);
            double dx = (bv + vv) / 4.0;
            bv = vv;
            d += dx;
        }
    }
    cout << setprecision(14);
    cout << d << endl;
}