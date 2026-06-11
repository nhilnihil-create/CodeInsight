#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
#define dump(a) cout << (a) << endl;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<double> t(n+1, 0), v(n+2, 0);
    for( int i = 1; i <= n; i++ ) cin >> t[i];
    for( int i = 0; i < n; i++ ) t[i+1] += t[i];
    for( int i = 1; i < n+1; i++ ) cin >> v[i];
    vector<double> g;
    for( double time = 0.0; time <= t.back(); time+=0.5 ) {
        double mi = __DBL_MAX__;
        for( int i = 0; i < n; i++ ) {
            double ma;
            if( 0 <= time && time < t[i] ) {
                ma = v[i+1]+(t[i]-time);
            }
            else if( t[i] <= time && time <= t[i+1] ) {
                ma = v[i+1];
            }
            else if( t[i+1] < time && time <= t.back() ) {
                ma = v[i+1]+(time-t[i+1]);
            }
            ma = min( ma, min( time, t.back()-time ) );
            mi = min( mi, ma );
        }
        g.push_back( mi );
    }
    double sum = 0.0;
    for( int i = 0; i < (int)g.size()-1; i++ ) sum += 0.25*(g[i]+g[i+1]);
    printf( "%lf\n", sum );
    return 0;  
}