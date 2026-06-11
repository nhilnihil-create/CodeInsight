#include <bits/stdc++.h>
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
    int n; cin >> n;
    double t, a; cin >> t >> a;
    V<double> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    int ans = 1;
    double pre = abs(a - (t - h[0] * 0.006));
    for(int i = 1; i < n; i++){
        double tmp = t - h[i] * 0.006;
        if(abs(a - tmp) < pre){
            pre = abs(a - tmp);
            ans = i + 1;
        }
    }
    cout << ans << endl;


    return 0;
}
