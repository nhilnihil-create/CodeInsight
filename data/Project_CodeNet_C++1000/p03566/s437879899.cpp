#include <bits/stdc++.h>
using namespace std;


int main()
{
    int N;
    cin >> N;
    vector<int> t(N+2, 0), v(N+2, 0);
    for(int i = 1; i <= N; i++) cin >> t[i];
    for(int i = 1; i <= N; i++) cin >> v[i];
 
    
    // l[i] <= t <= r[i] についてチェックする
    // ただし、l[0] = l[1] = 0, r[N] = r[N+1] = tend
    vector<int> l(N+2, 0), r(N+2, 0);
    for(int i = 2; i < N+2; i++) l[i] = l[i-1] + t[i-1];
    for(int i = 1; i < N+2; i++) r[i] = r[i-1] + t[i];

    vector<double> maxv;
    for(double x = 0; x <= r[N+1]; x += 0.5) {
        double minv = 100;
        for(int i = 0; i < N+2; i++) {
            if( x <= l[i] )           minv = min( minv, v[i] + (l[i] - x) );
            if( l[i] < x && x < r[i]) minv = min( minv, (double) v[i] );
            if( r[i] <= x )           minv = min( minv, v[i] + (x - r[i]) );
        }
        maxv.push_back( minv );
    }
 
    double ans = 0;
    for(int i = 1; i < maxv.size(); i++) ans += 0.5 * (maxv[i] + maxv[i-1]) / 2;
    cout << fixed << setprecision(3) << ans << endl;
 
    return 0;
}