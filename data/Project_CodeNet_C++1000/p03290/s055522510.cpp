#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;


int main () {
    int d, g;
    cin >> d >> g;
    vector<int> p(11);
    vector<int> c(11);
    rep(i, d) {
        cin >> p[i] >> c[i]; 
    }

    int ans = INF;
    for(int mask = 0; mask < (1 << d); mask++) {
        int s = 0; int num = 0; int rest_mask = -1;
        rep(i, d) {
            if(mask >> i & 1) {
                s += 100 * (i+1) * p[i] + c[i];
                num += p[i];
            } else {
                rest_mask = i;
            }
        }
        if (s < g) {
            int s1 = 100 * (rest_mask + 1);
            int need = (g - s + s1 - 1) / s1;
            if(need >= p[rest_mask]){
                continue;
            }
            num += need;
        }
        ans = min(ans, num);
    }
    cout << ans << endl;
}