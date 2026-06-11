#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(string s, int n, int k) {
    ll d = 0, m = 0, dm = 0, dmc = 0;
    for (int i = 0; i < k - 1; i++) {
        switch (s[i]) {
        case 'D':
            d++;
            break;
        case 'M':
            m++;
            dm += d;
            break;
        case 'C':
            dmc += dm;
            break;
        }
    }
    for (int i = k - 1; i < n; i++) {
        switch (s[i]) {
        case 'D':
            d++;
            break;
        case 'M':
            m++;
            dm += d;
            break;
        case 'C':
            dmc += dm;
            break;
        }
        switch (s[i - k + 1]) {
        case 'D':
            d--;
            dm -= m;
            break;
        case 'M':
            m--;
            break;
        }
    }
    return dmc;
}

int main() {
    int n, q;
    string s;
    cin >> n >> s >> q;
    int ks[q];
    for (int i = 0; i < q; i++) {
        cin >> ks[i];
    }

    for (int k: ks) {
        cout << solve(s, n, k) << endl;
    }
    return 0;
}
