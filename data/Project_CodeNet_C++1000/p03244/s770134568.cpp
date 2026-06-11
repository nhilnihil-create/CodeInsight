#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;




int main() {
    int n;
    cin >> n;
    map<int,int> m1, m2;
    rep(i,n/2) {
        int a, b;
        cin >> a >> b;
        m1[a]++;
        m2[b]++;
    }
    int max1 = 0, max2 = 0;
    vector<int> maxa, maxb;

    for (auto ite = m1.begin(); ite != m1.end(); ite++) {
        max1 = max(max1, ite->second);
    }
    for (auto ite = m2.begin(); ite != m2.end(); ite++) {
        max2 = max(max2, ite->second);
    }
    for (auto ite = m1.begin(); ite != m1.end(); ite++) {
        if (max1 == ite->second) {
            maxa.push_back(ite->first);
        }
    }
    for (auto ite = m2.begin(); ite != m2.end(); ite++) {
        if (max2 == ite->second) {
            maxb.push_back(ite->first);
        }
    }

    if (maxa.size() == 1 && maxb.size() == 1 && maxa[0] == maxb[0]) {
        int max1sub = 0, max2sub = 0;
        for (auto ite = m1.begin(); ite != m1.end(); ite++) {
            if (ite->second != max1) max1sub = max(max1sub, ite->second);
        }
        for (auto ite = m2.begin(); ite != m2.end(); ite++) {
            if (ite->second != max2) max2sub = max(max2sub, ite->second);
        }
        cout << n - max1 - max(max1sub,max2sub) << endl;
    }
    else {
        cout << n - max1 - max2 << endl;
    }
}