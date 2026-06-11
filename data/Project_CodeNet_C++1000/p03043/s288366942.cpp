#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    ld n, k; cin >> n >> k;

    ld ans = 0;
    V<ld> v(n);
    for(int i = 1; i <= n; i++){
        ll t = i, cnt = 0;
        if(t < k){
            while(1){
                t *= 2;
                cnt++;
                if(k <= t) break;
            }
            ans += (1 / (ld)(pow(2, cnt) * n));
        }else{
            ans += (1 / n);
        }
    }
    cout << setprecision(15) << ans << endl;

    return 0;
}
