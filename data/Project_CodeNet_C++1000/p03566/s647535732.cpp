#include <bits/stdc++.h>
using namespace std;


int main()
{
    int N;
    cin >> N;
    vector<double> t(N+2, 0), v(N+2, 0);
    for(int i = 1; i <= N; i++) cin >> t[i];
    for(int i = 1; i <= N; i++) cin >> v[i];
 
 
    vector<double> l(N+2, 0), r(N+2, 0);
    for(int i = 2; i < N+2; i++) l[i] = l[i-1] + t[i-1];
    for(int i = 1; i < N+2; i++) r[i] = r[i-1] + t[i];

    vector<double> sv;
    for(double x = 0; x <= r[N+1]; x += 0.5) {
        double minv = 1e9+1;
        for(int i = 0; i < N+2; i++) {
            if( x <= l[i] ) minv = min(minv, v[i] + (l[i] - x));
            if( l[i] < x && x < r[i]) minv = min(minv, v[i]);
            if( r[i] <= x ) minv = min(minv, v[i] + (x - r[i]));
        }
        sv.push_back(minv);
    }
 
    double ans = 0;
    for(int i = 1; i < sv.size(); i++) ans += 0.25 * (sv[i] + sv[i-1]);

    cout << fixed << setprecision(3) << ans << endl;
 
    return 0;
}