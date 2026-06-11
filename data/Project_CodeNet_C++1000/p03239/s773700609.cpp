#include <bits/stdc++.h>
#include <utility>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long

const int MOD =  1000000007;
const int IINF = INT_MAX;
const ll INF = 1LL << 60;


int main() {
    int n, t; cin >> n >> t;
    V<P<int, int> > v(n);
    for(int i = 0; i < n; i++){
        int c, d; cin >> c >> d;
        v[i] = make_pair(c, d);
    }

    int ans = IINF;
    for(int i = 0; i < n; i++){
        if(v[i].second <= t){
            ans = min(ans, v[i].first);
        }
    }
    if(ans != IINF) cout << ans << endl;
    else cout << "TLE" << endl;

    return 0;
}
