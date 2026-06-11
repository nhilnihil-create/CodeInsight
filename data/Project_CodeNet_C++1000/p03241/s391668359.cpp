#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> divs = {};
    for (int i = 1; i <= sqrt(m); i++) {
        if (m % i != 0) continue;
        divs.push_back(i);
        divs.push_back(m / i);
    }

    int gcdmax = -1;
    rep(i, divs.size()) {
        int md = m / divs[i];
        if (n > md) continue;
        gcdmax = max(divs[i], gcdmax);
    }

    cout << gcdmax << endl;
}