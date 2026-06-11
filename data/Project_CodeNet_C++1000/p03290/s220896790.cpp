#include <bits/stdc++.h>
using namespace std;

int main() {
    int d, g;
    cin >> d >> g;

    vector<int> p(d), c(d);

    for (int i = 0; i < d; i++) {
        cin >> p.at(i);
        cin >> c.at(i);
    }
    int answer = 1001;

    for (int bit = 0; bit < (1 << d); bit ++) {
        int total = 0;
        int count = 0;
        for (int i = 0; i < d; i++) {
            if (bit & (1 << i)) {
                total += (i + 1) * 100 * p.at(i) + c.at(i);
                count += p.at(i);
            }
        }
        if (total < g) {
            int maxUnused = -1;
            for (int i = d - 1; i >= 0; i--) {
                if (!(bit & (1 << i))){
                    maxUnused = i;
                    break;
                }
            }
            if(maxUnused >= 0) {
                for (int i = 0; i < p.at(maxUnused); i++) {
                    total += (maxUnused + 1) * 100;
                    count ++;
                    if (total >= g) break;
                }
            }
        }
        if (total >= g) answer = min(answer, count);
    }
    cout << answer << endl;


    return 0;
}