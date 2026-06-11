// Template
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <numeric>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
const int MOD = 1000000007;

#define v_exists(elem, v) find(v.begin(),v.end(),elem)!=v.end()
#define s_exists(elem, s) s.find(elem)!=s.end()
#define mod_mul(x, y) x*y%MOD
#define mod_add(x, y) (x+y)%MOD
#define mod_sub(x, y) (x-y)%MOD
#define REP(i, n) for(int i = 0;i < n;i++)
#define INF 1 << 10


long gcd(long a, long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long lcm( long m, long n ){
    if ( ( 0 == m ) || ( 0 == n ) )
        return 0;

    return ((m / gcd(m, n)) * n);
}



int main(){
    int n; cin >> n;
    std::vector<int> v(n+1);
    std::vector<int> t(n+1);
    for(int i=1; i<=n; i++){
        cin >> t[i];
        t[i] += t[i-1];
    }

    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    v.push_back(0);

    std::vector<double> maxv(2*t[n]+1);

    int ti = 1;
    for(int i=1; i<=n ; i++){
        while(ti < 2*t[i]){
            maxv[ti] = v[i];
            ti++;
        }
        maxv[ti] = min(v[i], v[i+1]);
        ti++;
    }

    for(int i = 1; i < 2*t[n]; i++) {
        maxv[i] = min(maxv[i], maxv[i-1]+0.5);
    }

    for(int i=2*t[n]-1; i>=0; i--){
        maxv[i] = min(maxv[i], maxv[i+1]+0.5);
    }

    double ans = 0;
    for (int i = 0; i < 2*t[n]; i++) {
        ans += 0.25*(maxv[i]+maxv[i+1]);
    }

    cout << fixed << ans << endl;



    return 0;

}
