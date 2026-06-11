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
    V<int> x(n), y(n), h(n);
    int p = 0;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i] >> h[i];
        if(p == 0 && h[i]) p = i;
    }

    for(int i = 0; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            ll tmp1 = h[p] + abs(x[p] - i) + abs(y[p] - j);
            bool ok = true;
            for(int k = 0; k < n; k++){
                ll tmp2 = max(tmp1 - abs(x[k] - i) - abs(y[k] - j), 0LL);
                if (tmp2 != h[k]) {
                    ok = false;
                    break;
                }
            }
            if(ok){
                cout << i << ' ' << j << ' ' << tmp1 << endl;
                return 0;
            }
        }
    }

    return 0;
}
