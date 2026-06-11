#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int64_t D, G;
    cin >> D >> G;
    vector<int> p(D), c(D);
    rep(i, D){
        cin >> p.at(i);
        cin >> c.at(i);
    }
    int ans = 1001;
    for (int bit = 0; bit < (1 << D); bit++){
        int count = 0;
        int64_t sum = 0;
        rep(i, D){
            if (bit & (1 << i)){
                sum += p.at(i) * 100 * (i + 1) + c.at(i);
                count += p.at(i);
            }
        }
        if (sum >= G) ans = min(ans, count);
        else{
            for (int j = D - 1; j >= 0; j--){
                if (!(bit & (1 << j))){
                    rep(k, p.at(j) - 1){
                        count++;
                        sum += 100 * (j + 1);
                        if (sum >= G) break;
                    }
                }
                if (sum >= G) break;
            }
            if (sum >= G) ans = min(ans, count);
        }
    }
    cout << ans << endl;
}
