#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, g, ans = 0, es, numpro, mus;
    cin >> d >> g;
    vector<int> p(d), c(d);
    for (int i = 0; i < d; i++) {
        cin >> p.at(i) >> c.at(i);
        ans += p.at(i);
    }
    for (int bit = 0; bit < (1 << d); bit++) {
        vector<bool> solved(d, false);
        es = 0;
        numpro = 0;
        mus = d;
        for (int i = 0; i < d; i++) {
            if(bit & (1 << i)) {
                es += 100 * (i + 1) * p.at(i) + c.at(i);
                numpro += p.at(i);
                if(!(bit & (1 << (i - 1)))) mus = i - 1;
            }
        }
        if(!(bit & (1 << (d - 1)))) mus = d - 1; 
        if (es >= g) ans = min(ans, numpro);
        else {
            if(g - es > p.at(mus) * 100 * (mus + 1)) continue;
            else numpro += (g - es + 100 * (mus + 1) - 1) / (100 * (mus + 1));
        }
        ans = min(ans, numpro);
    }
    cout << ans << endl;
}