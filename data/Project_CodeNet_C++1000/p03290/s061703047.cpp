#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, g, ans = 0, eachsum, numpro;
    cin >> d >> g;
    vector<int> p(d), c(d);
    for (int i = 0; i < d; i++) {
        cin >> p.at(i) >> c.at(i);
        ans += p.at(i);
    }
    for (int bit = 0; bit < (1 << d); bit++) {
        vector<bool> solved(d, false);
        eachsum = 0;
        numpro = 0;
        for (int i = 0; i < d; i++) {
            if(bit & (1 << i)) {
                eachsum += 100 * (i + 1) * p.at(i) + c.at(i);
                numpro += p.at(i);
                solved.at(i) = true;
            }
        }
        if (eachsum >= g) ans = min(ans, numpro);
        else {
            for (int i = d - 1; i >= 0; i--) {
                if (solved.at(i)) continue;
                for (int j = 1; j <= p.at(i); j++){
                    eachsum += 100 * (i + 1);
                    if (j == p.at(i)) eachsum += c.at(i);
                    numpro++;
                    if (eachsum >= g) break;
                }
                if (eachsum >= g) break;
            }
        }
        ans = min(ans, numpro);
    }
    cout << ans << endl;
}